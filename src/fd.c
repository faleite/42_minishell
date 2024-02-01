/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:04:23 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/01 23:38:30 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

int		ft_open_infile_heredoc(t_command *current, char *delimiter)
{
	int	fd;
	char	*str;

	if (current->infile_fd != -1)
		close(current->infile_fd);
	fd = open("heredoc_file", O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while (true)
	{
		str = readline("> ");
		if (!str || ft_strncmp(str, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			free(str);
			break ;
		}
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
	close(fd);
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
		if (access(file, F_OK | R_OK) == -1)
		{
			printf("File doesn't have privieliges to read!\n");
			exit(0);
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
			// exit(0);
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
			exit(0);
		}
	}
	return (1);
}

void		ft_open_all_infile(t_command *current)
{
	int	i;
	t_enum_token	token_id;

	i = 0;
	while (current->prompt->tokens[i])
	{
		token_id = current->prompt->tokens_id[i];
		if (token_id == INFILE_ID)
			ft_open_infile(current, current->prompt->tokens[i]);
		else if (token_id == HEREDOC_ID)
			ft_open_infile_heredoc(current, current->prompt->tokens[i]);
		i++;
	}
}

void		ft_open_all_outfile(t_command *current)
{
	int	i;
	t_enum_token	token_id;

	i = 0;
	while (current->prompt->tokens[i])
	{
		token_id = current->prompt->tokens_id[i];
		if (token_id == OUTFILE_ID)
			ft_open_outfile(current, current->prompt->tokens[i]);
		else if (token_id == APPEND_ID)
			ft_open_outfile_append(current, current->prompt->tokens[i]);
		i++;
	}
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
				ft_open_all_infile(current);
			else if (i == 1)
				ft_open_all_outfile(current);
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