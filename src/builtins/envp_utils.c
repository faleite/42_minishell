/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:46:00 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/08 17:20:38 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_value(char *name, char *value)
{
	t_envp		*current;

	current = data()->envp;
	while (current)
	{
		if (ft_strncmp(current->name, name, ft_strlen(name)) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			break ;
		}
		current = current->next;
	}
	getevarr()->envp = update_env();
}

char	*get_value(char *name)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		if (ft_strncmp(current->name, name, ft_strlen(name)) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
