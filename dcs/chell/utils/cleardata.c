/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleardata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: eportela <eportela@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/09/21 15:26:43 by eportela          #+#    #+#             */
/*   Updated: 2023/09/21 15:26:43 by eportela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_linkedlst(t_command_list *cmd_lst)
{
	t_command_list	*to_clean;

	to_clean = NULL;
	if (cmd_lst->next != NULL)
		to_clean = cmd_lst->next;
	free(cmd_lst);
	if (to_clean)
		free_linkedlst(to_clean);
}

void	free_args(t_arg *arg)
{
	int	i;

	i = 0;
	while (arg[i].token != NULL)
	{
		free(arg[i].token);
		i++;
	}
	free(arg);
}

void	free_splitter(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_all(t_command_list *cmd_lst, char *changes, char **splitter)
{
	free_linkedlst(cmd_lst);
	free(changes);
	free_splitter(splitter);
}
