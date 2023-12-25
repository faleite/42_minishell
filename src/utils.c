/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:46:39 by feden-pe          #+#    #+#             */
/*   Updated: 2023/12/20 19:31:15 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

t_shell	*create_node(char **full_cmd)
{
	t_shell	*new;

	new = malloc(sizeof(t_shell));
	if (!new)
		return (NULL);
	new->full_cmd = full_cmd;
	new->full_path = NULL;
	new->next = NULL;
	return (new);
}

void	add_tail(t_shell **head, t_shell *node)
{
	t_shell	*tmp;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

int	list_len(t_shell **stack)
{
	if (!*stack)
		return (0);
	else
		return (1 + list_len(&(*stack)->next));
}
