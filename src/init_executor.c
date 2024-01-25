/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:33:49 by feden-pe          #+#    #+#             */
/*   Updated: 2024/01/25 20:44:26 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

t_command	*new_struct(t_prompt *prompt, t_command *head)
{
	t_command	*new;
	t_command	*current;
	int			i;

	i = 0;
	new = ft_calloc(1, sizeof(t_command));
	new->path = cmd_path(getev()->envp, prompt->args[0]);
	new->args = prompt->args;
	while (prompt->tokens[i++])
	{
		if (prompt->tokens_id[i] == OUTFILE_ID)
			new->outfile = prompt->tokens[i];
		else if (prompt->tokens_id[i] == INFILE_ID)
			new->infile = prompt->tokens[i];
	}
	if (!head)
		return (new);
	else
	{
		current = head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (head);
}

void	init_exec(t_prompt *prompt)
{
	t_command	*head;

	head = ft_calloc(1, sizeof(t_command));
	while (prompt->next)
		head = new_struct(prompt, head);
}
