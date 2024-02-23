/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:00:55 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/23 22:14:03 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exit_msg(char *str)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	data()->exit_status = 1;
}

static char	*get_name(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = NULL;
	if (*str == '=')
	{
		exit_msg(str);
		return (NULL);
	}
	while (str[i] && str[i] != '=')
		i++;
	new = ft_calloc(i + 1, sizeof(char));
	while (--i >= 0)
		new[i] = str[i];
	return (new);
}

void	env(int outfile)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		if (current->value)
		{
			ft_putstr_fd(current->name, outfile);
			ft_putstr_fd("=", outfile);
			ft_putendl_fd(current->value, outfile);
		}
		current = current->next;
	}
	data()->exit_status = 0;
}

static void	ft_export_noarg(int outfile)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		ft_putstr_fd("declare -x ", outfile);
		ft_putstr_fd(current->name, outfile);
		if (current->value)
		{
			ft_putstr_fd("=\"", outfile);
			ft_putstr_fd(current->value, outfile);
			ft_putstr_fd("\"", outfile);
		}
		ft_putstr_fd("\n", outfile);
		current = current->next;
	}
	data()->exit_status = 0;
}

void	ft_export(char **key_value, int outfile)
{
	int		i;
	char	*name;

	i = 0;
	if (key_value && key_value[i + 1] == NULL)
	{
		ft_export_noarg(outfile);
		return ;
	}
	while (key_value && key_value[++i])
	{
		name = get_name(key_value[i]);
		if (!name)
			continue ;
		if (in_str(name, '-') || in_str(name, '?') \
			|| in_str(name, '@') || is_num(name) \
			|| (!in_str(key_value[i], '=') && (in_str(name, '+'))))
			exit_msg(key_value[i]);
		else
			export_keys(key_value, name, i);
		free(name);
	}
	getevarr()->envp = update_env(getevarr()->envp);
}
