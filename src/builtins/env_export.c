/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:00:55 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/22 22:29:22 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	exit_msg(char *str)
{
	data()->exit_status = 1;
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
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
	t_envp	*new_node;
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
		if (in_str(name, '-') || in_str(name, '?') || in_str(name, '@') || is_num(name) || (!in_str(key_value[i], '=') && (in_str(name, '+'))))
			exit_msg(key_value[i]);
		else if (node_exists(name))
			update_value(name, add_value(key_value[i]));
		else if (in_str(key_value[i], '='))
		{
			new_node = insert_end_envp(&data()->envp);
			new_node->name = ft_strdup(add_name(key_value[i]));
			new_node->value = ft_strdup(add_value(key_value[i]));
			data()->exit_status = 0;
		}
		else if (!in_str(key_value[i], '='))
		{
			new_node = insert_end_envp(&data()->envp);
			new_node->name = ft_strdup(add_name(key_value[i]));
			new_node->value = NULL;
			data()->exit_status = 0;
		}
		free(name);
	}
	getevarr()->envp = update_env(getevarr()->envp);
}
