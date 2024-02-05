/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:37:33 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/31 12:26:59 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
cat <<"" or cat <<''
> $USER
> 
$USER
Obs: quotes, never handle
Obs: << eof (expande tudo, inclusive c/ aspas)
Obs: << "eof" or 'eof' (expande nada)
*/
int	handle_heredoc(char **tokens)
{
	int		i;
	int		quotes;
	char	*heredoc;
	char	*eof;
	char	*out;

	i = 0;
	eof = ft_strdup("");
	out = ft_strdup("");
	while (tokens && tokens[i])
	{
		heredoc = "";
		if (!ft_strcmp(tokens[i], HERE_DOC) && tokens[++i])
			process_heredoc(&tokens[i], &eof, &out, &i);
		else
			i++;
	}
	free(out);
	free(eof);
	return (0);
}

void	process_heredoc(char **token, char **eof, char **out, int *i)
{
	int		quotes;
	char	*heredoc;

	quotes = 0;
	heredoc = "";
	while (heredoc)
	{
		quotes = trim_quotes(*token, &(*eof));
		heredoc = readline("> ");
		if (!heredoc)
		{
			msg_error_hd(*token);
			write_heredoc(&(*token), &(*eof), &(*out), &quotes);
			(*i)++;
		}
		else if (!ft_strcmp(heredoc, *eof))
		{
			write_heredoc(&(*token), &(*eof), &(*out), &quotes);
			(*i)++;
			break ;
		}
		else
			fill_documents(heredoc, &(*out));
	}
}

void	write_heredoc(char **token, char **eof, char **out, int *quotes)
{
	int		fd;
	char	*expander;

	fd = open_heredoc();
	expander = ft_strdup("");
	if (!(*quotes))
	{
		free(expander);
		expander = expander_hd(*out);
		write(fd, expander, ft_strlen(expander));
		free(expander);
	}
	else
	{
		write(fd, *out, ft_strlen(*out));
		free(expander);
	}
	free(*token);
	*token = ft_strdup("heredoc_file");
	free(*out);
	free(*eof);
	*out = ft_strdup("");
	*eof = ft_strdup("");
	close(fd);
}
