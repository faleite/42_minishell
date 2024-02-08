/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:53:59 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/08 17:12:35 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_envp(t_envp *head)
{
	t_envp	*current;
	t_envp	*tmp;

	current = head;
	while (current && current->value && current->name)
	{
		tmp = current;
		current = current->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
	head = NULL;
}

void	free_path(char	*str)
{
	free(str);
}
