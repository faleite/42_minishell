/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:43:17 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 11:39:24 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file(int *fd, char *filename, int flags, int perms)
{
	if (*fd != -1)
		close(*fd);
	*fd = open(filename, flags, perms);
	if (*fd == -1)
		return (1);
	return (0);
}

void	revert_fds(t_command_list *cmd_lst)
{
	dup2(cmd_lst->stdin, STDIN_FILENO);
	close(cmd_lst->stdin);
	dup2(cmd_lst->stdout, STDOUT_FILENO);
	close(cmd_lst->stdout);
}

int	do_pipes(t_command_list *cmd_lst, t_pipe *pipes)
{
	if (cmd_lst->next)
	{
		pipe(pipes->fd);
		pipes->open = 1;
		if (cmd_lst->out_fd == -1)
			cmd_lst->out_fd = pipes->fd[1];
	}
	if (pipes->next->open == 1)
		cmd_lst->in_fd = pipes->next->fd[0];
	return (0);
}

int	assign_fds(int in_fd, int out_fd)
{
	if (in_fd != -1)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (out_fd != -1)
	{
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
	return (0);
}
