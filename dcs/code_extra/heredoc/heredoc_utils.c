/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:13:43 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/31 12:28:08 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	fill_documents(char *doc, char **bkp)
{
	char	*line;
	char	*tmp;

	line = ft_strjoin(doc, " \n");
	tmp = *bkp;
	*bkp = ft_strjoin(*bkp, line);
	free(tmp);
	free(line);
}

int	trim_quotes(char *token, char **eof)
{
	free(*eof);
	if (token[0] == '\'')
		*eof = ft_strtrim(token, "\'");
	else if (token[0] == '\"')
		*eof = ft_strtrim(token, "\"");
	else
		*eof = ft_strdup(token);
	if (token[0] == '\'' || token[0] == '\"')
		return (1);
	return (0);
}

int	open_heredoc(void)
{
	int	fd;

	fd = open("heredoc_file", O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		ft_putendl_fd("Error opening heredoc file", 2);
		return (-1);
	}
	return (fd);
}

void	msg_error_hd(char *type_err)
{
	ft_putstr_fd("minishell: warning: here-document ", STDERR_FILENO);
	ft_putstr_fd("delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(type_err, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
}
