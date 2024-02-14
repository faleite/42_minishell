/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:04:23 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/14 21:28:32 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

static void	error_msg(char *delimiter)
{
	ft_putstr_fd("minishell: warning: here-document ", STDERR_FILENO);
	ft_putstr_fd("delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(delimiter, STDERR_FILENO);
	ft_putendl_fd("')", STDERR_FILENO);
}

int		ft_open_infile_heredoc(t_command *current, char *delimiter)
{
	char	*str;
	int 	pid;

	if (current->infile_fd != -1)
	 	close(current->infile_fd);
	pid = fork();
	signal(SIGINT, handle_sigint);
	if (pid == 0)
	{
		signal(SIGINT, handle_sigint_clean);
		data()->h_fd = open("heredoc_file", O_CREAT | O_WRONLY | O_TRUNC, 0664);
		while (true)
		{
			str = readline("> ");
			if (!str || ft_strncmp(str, delimiter, ft_strlen(delimiter) + 1) == 0)
			{
				if (!str)
					error_msg(delimiter);
				free(str);
				clean_newline();
				close(data()->h_fd);
				break ;
			}
			write(data()->h_fd, str, ft_strlen(str));
			write(data()->h_fd, "\n", 1);
		}
		close(data()->h_fd);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	current->infile_fd = open("heredoc_file", O_RDONLY);
	if (current->infile_fd == -1)
	 	printf("Error on opening heredoc file\n");
	return (1);
}

int		ft_open_infile(t_command *current, char *file)
{
	int	error_id;

	if (current->infile_fd != -1)
		close(current->infile_fd);
	current->infile_fd = open(file, O_RDONLY);
	if (current->infile_fd == -1)
	{
		if (access(file, F_OK) == -1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(file, STDERR_FILENO);
			ft_putendl_fd(": No such file or directory", STDERR_FILENO);
			return (0);
		}
		else if (access(file, F_OK | R_OK) == -1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(file, STDERR_FILENO);
			ft_putendl_fd(": Permission denied", STDERR_FILENO);
			clean_newline();
			return (0);
		}
	}
	return (1);
}

int		ft_open_outfile_append(t_command *current, char *outfile)
{
	int	error_id;

	if (current->outfile_fd != -1)
		close(current->outfile_fd);
	current->outfile_fd = open(outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (current->outfile_fd == -1)
	{
		if (access(outfile, F_OK | W_OK | R_OK) == -1)
		{
			printf("File doesn't have privieliges to read &| write!\n");
			clean_newline();
			current->is_exec = 0;
			return (0);
		}
	}
	return (1);
}

int		ft_open_outfile(t_command *current, char *outfile)
{
	int	error_id;

	if (current->outfile_fd != -1)
		close(current->outfile_fd);
	current->outfile_fd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (current->outfile_fd == -1)
	{
		if (access(outfile, F_OK | W_OK | R_OK) == -1)
		{
			printf("File doesn't have privieliges to read &| write!\n");
			clean_newline();
			current->is_exec = 0;
			return (0);
		}
	}
	return (1);
}

int		ft_open_all_infile(t_command *current)
{
	int	i;
	t_enum_token	token_id;

	i = 0;
	while (current->prompt->tokens[i])
	{
		token_id = current->prompt->tokens_id[i];
		if (token_id == INFILE_ID)
		{
			if (ft_open_infile(current, current->prompt->tokens[i]) == 0)
				return (0);
		}
		else if (token_id == HEREDOC_ID)
		{
			if (ft_open_infile_heredoc(current, current->prompt->tokens[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int		ft_open_all_outfile(t_command *current)
{
	int	i;
	t_enum_token	token_id;

	i = 0;
	while (current->prompt->tokens[i])
	{
		token_id = current->prompt->tokens_id[i];
		if (token_id == OUTFILE_ID)
		{
			if (ft_open_outfile(current, current->prompt->tokens[i]) == 0)
				return (0);
		}
		else if (token_id == APPEND_ID)
		{
			if (ft_open_outfile_append(current, current->prompt->tokens[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int		ft_open_all(t_command *head)
{
	int	i;
	t_command	*current;
	
	i = 0;
	while (i <= 1)
	{
		current = head;
		while (current)
		{
			if (i == 0)
			{
				if (ft_open_all_infile(current) == 0)
				{
					current->is_exec = 0;
					break ;
				}
			}
			else if (i == 1)
			{
				if (ft_open_all_outfile(current) == 0)
				{
					current->is_exec = 0;
					break ;
				}
			}
			current = current->next;
		}
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char *str = "lol.txt";
// 	static t_command new;
// 	new.infile = str;
// 	ft_open_infile(&new);
// 	printf("%d", new.fd[0]);
// }
