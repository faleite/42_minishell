/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:46:00 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/20 20:03:40 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_value(char *name, char *value)
{
	t_envp		*current;

	current = data()->envp;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			getevarr()->envp = update_env(getevarr()->envp);
			return ;
		}
		current = current->next;
	}
	current = insert_end_envp(&data()->envp);
	current->name = ft_strdup(name);
	current->value = ft_strdup(value);
	getevarr()->envp = update_env(getevarr()->envp);
}

char	*get_value(char *name)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (current->value);
		current = current->next;
	}
	return ("\3");
}

int		node_exists(char *name)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}
