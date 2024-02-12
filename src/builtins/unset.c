/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 01:34:27 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/12 17:42:28 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_node(t_envp *node)
{
	free(node->name);
	free(node->value);
	free(node);
}

void	delete_node(char *name)
{
	t_envp	*current;
	t_envp	*tmp;

	current = data()->envp;
	if (!ft_strcmp(current->next->name, name))
	{
		data()->envp = current->next;
		free_node(current);
		return ;
	}
	while (current)
	{
		if (!ft_strcmp(current->next->name, name))
		{
			tmp = current->next;
			current->next = current->next->next;
			free_node(tmp);
			break ;
		}
		current = current->next;
	}
}

// static void	print_error(char *arg)
// {
// 	ft_putstr_fd("minishell: unset: ", 2);
// 	ft_putstr_fd(arg, 2);
// 	ft_putendl_fd(": invalid option", 2);
// }

void	unset(t_command *command)
{
	int	i;

	i = 0;
	while (command->args[++i])
			delete_node(command->args[i]);
}
