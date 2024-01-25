/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:59 by feden-pe          #+#    #+#             */
/*   Updated: 2024/01/25 20:45:02 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

pid_t	exec_command(t_command *command, int infile, int outfile)
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
		execve(command->path, command->args, getev()->envp);
		exit(127);
	}
	close(infile);
	close(outfile);
	return (command->pid);
}
