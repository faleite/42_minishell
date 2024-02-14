/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:38:43 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/14 20:57:34 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		commands_wait(t_command *head)
{
	int			i;
	t_command	*current;

	i = 0;
	current = head;
	while (current)
	{
		if (current->args && !is_builtin(current->args[0]) && current->is_exec)
			i++;
		current = current->next;
	}
	return (i);
}
