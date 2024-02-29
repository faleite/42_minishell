/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:26:39 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/29 15:55:56 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

void	check_open(t_command *current, int i)
{
	t_enum_token	token_id;

	token_id = current->prompt->tokens_id[i];
	if (token_id == OUTFILE_ID && \
			!ft_open_outfile(current, current->prompt->tokens[i]))
		return ;
	else if (token_id == APPEND_ID && \
			!ft_open_outfile_append(current, current->prompt->tokens[i]))
		return ;
	else if (token_id == INFILE_ID && \
			!ft_open_infile(current, current->prompt->tokens[i]))
		return ;
}

int	index_heredoc(t_command *current)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (current->prompt->tokens_id[i++])
	{
		if (current->prompt->tokens_id[i] == HEREDOC_ID)
			ret = i;
	}
	return (ret);
}

int	index_last_infile(t_command *current)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (current->prompt->tokens_id[i++])
	{
		if (current->prompt->tokens_id[i] == INFILE_ID)
			ret = i;
	}
	return (ret);
}

void	fuck_fds(void)
{
	size_t	fd;

	fd = 3;
	while (fd < FOPEN_MAX)
	{
		close(fd);
		fd++;
	}
}
