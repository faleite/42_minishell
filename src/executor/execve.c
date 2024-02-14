/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:59 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/14 21:24:57 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

static int	exec_command(t_command *command, int infile, int outfile)
{
	// return printf("Infile: %d Outfile: %d\n", infile, outfile);
	if (command->is_exec == 1)
	{
		command->pid = fork();
		if (command->pid < 0)
			exit(0);
		if (!command->pid)
		{
			if (dup2(infile, STDIN_FILENO) < 0)
				exit(0);
			if (infile != 0)
				close(infile);
			if (dup2(outfile, STDOUT_FILENO) < 0)
				exit(0);
			if (outfile != 1)
				close(outfile);
			if (command->path && \
					execve(command->path, command->args, getevarr()->envp) == -1)
				command_error(command);
			else
				command_error(command);
			clean_newline();
			exit(127);
		}
	}
	if (infile != 0)
		close(infile);
	if (outfile != 1)
		close(outfile);
	return (1);
}

void	wait_all(t_command *head)
{
	t_command	*current;
	t_command	*tail;
	int			status;
	pid_t		pid;
	int	 		i;

	i = 0;
	current = head;
	tail = find_tail(head);
	// print_commands(current);
	while (current)
	{
		if (current->is_exec == 1)
		{
			pid = waitpid(-1, &status, 0);
			if (pid == tail->pid)
			{
				if (WIFEXITED(status))
					data()->exit_status = WEXITSTATUS(status);
				else if (WIFSIGNALED(status))
					data()->exit_status = WTERMSIG(status) + 128;
			}
		}
		// printf("%d\n", i++);
		current = current->next;
	}
}

void	executing(t_command *head)
{
	t_command	*current;
	int			infile;
	int			outfile;

	current = head;
	infile = 0;
	while (current)
	{
		if (current->next && pipe(current->fd) == -1)
		{
			ft_putendl_fd("Error creating pipe", STDERR_FILENO);
			clean_newline();
			break ;
		}
		if (current->infile_fd != -1)
		{
			infile = current->infile_fd;
			if (current->fd[0] != 0)
				close(current->fd[0]);
		}
		outfile = current->fd[1];
		if (current->outfile_fd != -1)
		{
			outfile = current->outfile_fd;
			if (current->fd[1] != 1)
				close(current->fd[1]);
		}
		if (current->args && is_builtin(current->args[0]))
			builtins(current, infile, outfile);
		else
			exec_command(current, infile, outfile);
		infile = current->fd[0];
		current = current->next;
	}
	wait_all(head);
}

int	to_execute(t_command *head)
{
	t_command *current;

	current = head;
	while (current)
	{
		if (current->is_exec == 1)
			return (1);
		current = current->next;
	}
	return (0);
}
