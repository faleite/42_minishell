/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:00:55 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/06 05:01:45 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	env(int outfile)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		ft_putstr_fd(current->name, outfile);
		ft_putstr_fd("=", outfile);
		ft_putendl_fd(current->value, outfile);
		current = current->next;
	}
}

static void	ft_export_noarg(int outfile)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		ft_putstr_fd("declare -x ", outfile);
		ft_putstr_fd(current->name, outfile);
		ft_putstr_fd("=", outfile);
		ft_putstr_fd("\"", outfile);
		ft_putstr_fd(current->value, outfile);
		ft_putstr_fd("\"", outfile);
		ft_putstr_fd("\n", outfile);
		current = current->next;
	}
}

void	ft_export(char **key_value, int outfile)
{
	int		i;
	t_envp	*new_node;


	i = 0;
	if (key_value && key_value[i + 1] == NULL)
	{
		ft_export_noarg(outfile);
		return ;
	}
	while (key_value && key_value[++i])
	{
		new_node = insert_end_envp(&data()->envp);
		new_node->name = ft_strdup(add_name(key_value[i]));
		new_node->value = ft_strdup(add_value(key_value[i]));
	}
	getevarr()->envp = update_env();
}

