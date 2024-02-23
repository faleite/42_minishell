/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:55:36 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/23 22:15:34 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	error_msg(char *delimiter)
{
	close(data()->h_fd);
	ft_putstr_fd("minishell: warning: here-document ", STDERR_FILENO);
	ft_putstr_fd("delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(delimiter, STDERR_FILENO);
	ft_putendl_fd("')", STDERR_FILENO);
}

static int	check_readline(char *str, char *delimiter)
{
	if (!str || \
			ft_strncmp(str, delimiter, ft_strlen(delimiter) + 1) == 0)
	{
		if (!str)
			error_msg(delimiter);
		free(str);
		clean_newline();
		return (1);
	}
	return (0);
}

static void	open_heredoc(t_command *command)
{
	command->infile_fd = open("/tmp/heredoc_file", O_RDONLY);
	if (command->infile_fd == -1)
	{
		command->is_exec = 0;
		ft_putendl_fd("minishell: error on opening heredoc file" \
		, STDERR_FILENO);
	}
}

static void	open_hd(void)
{
	int	fd;

	fd = open("/tmp/heredoc_file", O_CREAT | O_WRONLY | O_TRUNC, 0664);
	data()->h_fd = fd;
}

int	ft_open_infile_heredoc(t_command *current, char *delimiter)
{
	char	*str;
	int		pid;

	if (current->infile_fd != -1)
		close(current->infile_fd);
	pid = fork();
	signal(SIGINT, handle_sigint);
	if (pid == 0)
	{
		signal(SIGINT, handle_sigint_clean);
		open_hd();
		while (true)
		{
			str = readline("> ");
			if (check_readline(str, delimiter))
				break ;
			ft_putendl_fd(str, data()->h_fd);
		}
		close(data()->h_fd);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	open_heredoc(current);
	return (current->is_exec);
}
