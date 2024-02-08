/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:11:10 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/08 17:20:13 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_open_quotes(char *token);

int	handle_quotes_err(t_token *lst)
{
	char	quotes;
	int		len;
	t_token	*curr;

	curr = lst;
	while (curr)
	{
		len = ft_strlen(curr->token) - 1;
		quotes = is_open_quotes(curr->token);
		if (quotes)
			return (msg_error(lst, (char []){quotes, '\0'}, 1));
		curr = curr->next;
	}
	return (0);
}

int	handle_big_redir(t_token *lst)
{
	t_token	*curr;

	curr = lst;
	while (curr)
	{
		if (!ft_strncmp(curr->token, ">>>", 3))
			return (msg_error(lst, ">", 1));
		else if (!ft_strncmp(curr->token, "<<<", 3))
			return (msg_error(lst, "<", 1));
		else if (!ft_strncmp(curr->token, ">><", 3))
			return (msg_error(lst, "<", 1));
		else if (!ft_strncmp(curr->token, "<<>", 3))
			return (msg_error(lst, ">", 1));
		else if (!ft_strncmp(curr->token, "<>", 2))
			return (msg_error(lst, ">", 1));
		else if (!ft_strncmp(curr->token, "><", 2))
			return (msg_error(lst, "<", 1));
		curr = curr->next;
	}
	return (0);
}

int	handle_newline_err(t_token *lst)
{
	t_token	*curr;

	curr = lst;
	while (curr)
	{
		if (!is_redirect(curr->token) && \
			(curr->prev == NULL && curr->next == NULL))
			return (msg_error(lst, "newline", 1));
		else if (!is_redirect(curr->token) && \
			(curr->next == NULL))
			return (msg_error(lst, "newline", 1));
		else if (curr->next && (!is_redirect(curr->token) && \
			!is_redirect(curr->next->token)))
			return (msg_error(lst, curr->next->token, 1));
		curr = curr->next;
	}
	return (0);
}

int	handle_pipe_err(t_token *lst)
{
	t_token	*curr;

	curr = lst;
	while (curr)
	{
		if (!ft_strcmp(curr->token, PIPE) && \
			(curr->prev == NULL || curr->next == NULL))
			return (msg_error(lst, PIPE, 1));
		else if (curr->next && !is_redirect(curr->token) && \
				!ft_strcmp(curr->next->token, PIPE))
			return (msg_error(lst, PIPE, 1));
		else if (!ft_strncmp(curr->token, "||", 2))
			return (msg_error(lst, PIPE, 1));
		else if (curr->next && !ft_strcmp(curr->token, PIPE) && \
				!ft_strcmp(curr->next->token, PIPE))
			return (msg_error(lst, PIPE, 1));
		else if (curr->next && !ft_strcmp(curr->token, PIPE) && \
				!ft_strcmp(curr->next->token, PIPE))
			return (msg_error(lst, PIPE, 1));
		curr = curr->next;
	}
	return (0);
}

static int	is_open_quotes(char *token)
{
	int		i;
	int		j;
	char	quotes;

	i = 0;
	j = 0;
	while (token[i])
	{
		quotes = '\0';
		while (token[i] && (token[i] != '\"' && token[i] != '\''))
			i++;
		if (token[i])
			quotes = token[i++];
		else
			return (0);
		while (token[i] && (token[i] != quotes))
			i++;
		if (!token[i])
			return (quotes);
		else
			i++;
	}
	return (0);
}
