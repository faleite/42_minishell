/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:04:23 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/17 13:49:20 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_open_infile(t_command *current, char *file)
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
		}
		else if (access(file, F_OK | R_OK) == -1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(file, STDERR_FILENO);
			ft_putendl_fd(": Permission denied", STDERR_FILENO);
			clean_newline();
		}
		current->is_exec = 0;
	}
	return (current->is_exec);
}

int	ft_open_outfile_append(t_command *current, char *outfile)
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
		}
	}
	return (current->is_exec);
}

int	ft_open_outfile(t_command *current, char *outfile)
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
		}
	}
	return (current->is_exec);
}

int	ft_open_heredoc_all(t_command *current)
{
	t_enum_token	token_id;
	int				i;

	i = -1;
	while (current->prompt->tokens[++i])
	{
		token_id = current->prompt->tokens_id[i];
		if (token_id == HEREDOC_ID && \
			!ft_open_infile_heredoc(current, current->prompt->tokens[i]))
			break ;
	}
	return (current->is_exec);
}

int	ft_open_all(t_command *head)
{
	t_command		*current;
	t_enum_token	token_id;
	int				i;

	current = head;
	while (current)
	{
		i = -1;
		ft_open_heredoc_all(current);
		while (current->prompt->tokens[++i])
		{
			token_id = current->prompt->tokens_id[i];
			if (token_id == OUTFILE_ID && \
				!ft_open_outfile(current, current->prompt->tokens[i]))
				break ;
			else if (token_id == APPEND_ID && \
				!ft_open_outfile_append(current, current->prompt->tokens[i]))
				break ;
			else if (token_id == INFILE_ID && \
				!ft_open_infile(current, current->prompt->tokens[i]))
				break ;
		}
		current = current->next;
	}
	return (1);
}
