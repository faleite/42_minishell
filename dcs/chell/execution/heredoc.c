/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:38:59 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/11 17:40:44 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_heredoc_error(char *str)
{
	ft_putstr_fd("minishell: warning: here-document delimited by end-of-file \
		(wanted `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("')", 2);
}

void	do_heredoc(t_data *data, int fd, char *heredoc, char *eof)
{
	char	*out;

	while (ft_strncmp(heredoc, eof, ft_strlen(eof) + 1))
	{
		free(heredoc);
		heredoc = readline("> ");
		if (!heredoc)
		{
			print_heredoc_error(eof);
			break ;
		}
		out = ft_strjoin(heredoc, "\n");
		if (heredoc && ft_strncmp(heredoc, eof, ft_strlen(eof) + 1))
			write(fd, out, ft_strlen(out));
		free(out);
	}
	if (data->pipes.open)
	{
		close(data->pipes.fd[0]);
		close(data->pipes.fd[1]);
	}
	close(fd);
	free(heredoc);
}

int	open_hd(void)
{
	int	fd;

	fd = open("heredoc_163465", O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		ft_putendl_fd("Error opening heredoc file", 2);
		return (-1);
	}
	return (fd);
}

int	mini_heredoc(t_data *data, char *eof, t_command_list *cmd_lst)
{
	char	*heredoc;
	int		fd;
	int		pid;

	pid = fork();
	if (pid == -1)
		return (ft_putendl_fd("Error forking", 2));
	if (pid != 0)
		signal(SIGINT, heredoc_sigint_handler);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		heredoc = ft_strdup("");
		fd = open_hd();
		if (fd == -1)
			return (-1);
		do_heredoc(data, fd, heredoc, eof);
		revert_fds(cmd_lst);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	signal(SIGINT, sigint_handler);
	return (0);
}
