/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:38:43 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/05 18:48:50 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		commands_wait(t_command *head)
{
	int			i;
	t_command	*current;

	i = 0;
	current = head;
	while (current)
	{
		if (current->args && !is_builtin(current->args[0]))
			i++;
		current = current->next;
	}
	return (i);
}
