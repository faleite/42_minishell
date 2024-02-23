/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:53:59 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/23 21:21:08 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr && arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	free_envp(t_envp *head)
{
	t_envp	*current;
	t_envp	*tmp;

	current = head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
	head = NULL;
}

void	free_struct(t_command *head)
{
	t_command	*current;
	t_command	*tmp;

	current = head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free_arr(tmp->args);
		free(tmp->path);
		free_prompt2(tmp->prompt);
		free(tmp);
	}
	head = NULL;
	free(head);
}
