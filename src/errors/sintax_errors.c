/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sintax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:31:52 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/09 18:44:46 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* FOR DEUGB USE: print_tokens(lst); */
int	sintax_errors(char *line)
{
	char		**tokens;
	t_token		*lst;

	lst = NULL;
	tokens = ft_lexer(line);
	parser_tokens(&lst, tokens);
	free_arr(tokens);
	if (handle_pipe_err(lst))
		return (data()->exit_status = 2);
	else if (handle_big_redir(lst))
		return (data()->exit_status = 2);
	else if (handle_newline_err(lst))
		return (data()->exit_status = 2);
	if (handle_quotes_err(lst))
		return (data()->exit_status = 2);
	free_tokens(&lst);
	return (0);
}

int	msg_error(t_token *lst, char *type_err, int exit_status)
{
	ft_putstr_fd("minishell: syntax error ", STDERR_FILENO);
	ft_putstr_fd("near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(type_err, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	free_tokens(&lst);
	return (exit_status);
}

int	is_redirect(char *token)
{
	if (!ft_strcmp(token, INFILE) || !ft_strcmp(token, OUTFILE) \
		|| !ft_strcmp(token, APPEND) || !ft_strcmp(token, HERE_DOC))
		return (0);
	return (1);
}
