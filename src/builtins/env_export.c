/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:00:55 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/05 03:43:37 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	env(void)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		ft_putstr_fd(current->name, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(current->value, 1);
		current = current->next;
	}
}

static void	ft_export_noarg(void)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(current->name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd("\"", 1);
		ft_putstr_fd(current->value, 1);
		ft_putstr_fd("\"", 1);
		ft_putstr_fd("\n", 1);
		current = current->next;
	}
}

void	ft_export(char **key_value)
{
	int		i;
	t_envp	*new_node;


	i = 0;
	if (key_value && key_value[i + 1] == NULL)
	{
		ft_export_noarg();
		return ;
	}
	while (key_value && key_value[++i])
	{
		new_node = insert_end_envp();
		new_node->name = ft_strdup(add_name(key_value[i]));
		new_node->value = ft_strdup(add_value(key_value[i]));
	}
}

