/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:59 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/29 18:14:33 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	exec_command(t_command *command, int infile, int outfile)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	if (command->is_exec == 1 && data()->is_exec_all == 1)
	{
		command->pid = fork();
		if (command->pid == 0)
		{
			signal(SIGQUIT, handle_signext);
			signal(SIGINT, handle_signext);
			ft_dup2(command, infile, outfile);
			if (command->path && \
				execve(command->path, command->args, \
				getevarr()->envp) == -1)
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

	current = head;
	status = 0;
	tail = find_tail(current);
	while (current)
	{
		if (current->args && !is_builtin(current->args[0]))
		{
			pid = waitpid(-1, &status, 0);
			if (pid == tail->pid)
			{
				if (!current->args[0])
					data()->exit_status = 0;
				else if (WIFEXITED(status))
					data()->exit_status = WEXITSTATUS(status);
				else if (WIFSIGNALED(status))
					data()->exit_status = WTERMSIG(status) + 128;
			}
		}
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
		outfile = 1;
		if (current->next && pipe(current->fd) == -1)
		{
			ft_putendl_fd("Error creating pipe", STDERR_FILENO);
			clean_newline();
			break ;
		}
		outfile = change_out(current, outfile);
		infile = change_in(current, infile);
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
	t_command	*current;

	current = head;
	while (current)
	{
		if (current->is_exec == 1)
			return (1);
		current = current->next;
	}
	return (0);
}
