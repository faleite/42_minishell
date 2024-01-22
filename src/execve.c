/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:59 by feden-pe          #+#    #+#             */
/*   Updated: 2024/01/22 18:19:27 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

pid_t	exec_command(t_shell *command, int infile, int outfile)
{
	command->pid = fork();
	if (command->pid < 0)
		exit(0);
	if (!command->pid)
	{
		if (dup2(infile, STDIN_FILENO) < 0)
			exit(0);
		close(infile);
		if (dup2(outfile, STDOUT_FILENO) < 0)
			exit(0);
		close(outfile);
		execve(command->cmds->path, command->cmds->args, command->envp);
		exit(127);
	}
	close(infile);
	close(outfile);
	return (command->pid);
}

void	open_fd(t_shell *command)
{
	int	i;

	i = 0;
	while (command->cmds->tokens_id[i++])
	{
		if (command->cmds->tokens_id[i] == (INFILE_ID || HEREDOC_ID))
			command->fd[0] = open(command->infile, O_RDONLY);
		else if (command->cmds->tokens_id[i] == APPEND_ID)
			command->fd[1] = open(command->outfile, O_WRONLY | O_CREAT | O_APPEND);
		else if (command->cmds->tokens_id[i] == OUTFILE_ID)
			command->fd[1] = open(command->outfile, O_WRONLY | O_CREAT | O_TRUNC);
	}
}
