/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:59 by feden-pe          #+#    #+#             */
/*   Updated: 2024/01/18 19:59:10 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"
#include <unistd.h>

pid_t	pipe_command(t_shell *command)
{
	int	pipe_fd[2];

	command->pid = fork();
	if (command->pid < 0)
		return (1);
	if (command->pid == 0)
	{
		// Child process
		close(pipe_fd[0]);
		if (pipe(pipe_fd) < 0)
			return (2);
		if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
			return (3);
		close(pipe_fd[1]);
		execve(command->cmds->path, command->cmds->args, command->envp);
	}
	return (command->pid);
}
