
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:39:59 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/01 23:37:44 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

static int	exec_command(t_command *command, int infile, int outfile)
{
	// return printf("Infile: %d Outfile: %d\n", infile, outfile);
	
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
		execve(command->path, command->args, getevarr()->envp);
		exit(127);
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

	current = head;
	while (current)
	{
		wait(NULL);
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
			break ;
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
		exec_command(current, infile, outfile);
		infile = current->fd[0];
		current = current->next;
	}
	wait_all(head);
}

int main (int ac, char *av[], char *ev[])
{

	static t_prompt	test;
	static t_prompt	test2;
	t_command	*head;

	// head = ft_calloc(1, sizeof(t_command));
	test.args = ft_calloc(10, sizeof(char *));
	test.tokens = ft_calloc(10, sizeof(char *));
	test.tokens_id = ft_calloc(10, sizeof(t_enum_token));

	test2.args = ft_calloc(10, sizeof(char *));
	test2.tokens = ft_calloc(10, sizeof(char *));
	test2.tokens_id = ft_calloc(10, sizeof(t_enum_token));

	test.args[0] = "cat";
	// test.args[1] = "oi";
	test.tokens[0] = "i";
	test.tokens_id[0] = HEREDOC_ID;
	// test.tokens[1] = "file";
	// test.tokens_id[1] = INFILE_ID;
	// test.next = &test2;

	test2.args[0] = "wc";
	test2.args[2] = NULL;
	// test2.tokens[0] = "infile.txt";
	// test2.tokens_id[0] = INFILE_ID;
	test2.next = NULL;
	
	ft_fillenvp(ev);
	ft_envp(getevarr()->envp);
	// print_envp();

	int	i = 0;
	head = init_exec(&test);
	ft_open_all(head);
	executing(head);
	print_commands(head);

	printf("\nExecuting complete");
}
