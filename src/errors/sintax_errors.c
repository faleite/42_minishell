/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sintax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:31:52 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/17 15:44:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Substitui separador
 * echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * echo/2"hello      there"/2how/2are/2'you 'doing?/2$USER/2|wc/2-l/2>outfile
*/
char	**ft_lexerd(char *s1)
{
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;
	char	**arr;

	arr = NULL;
	s2 = split_pipes(s1);
	s3 = split_redirects(s2);
	free(s2);
	replace_spaces(s3);
	//s4 = expander_outside(s3);
	//free(s3);
	//s5 = expander_inside(s4);
	//free(s4);
	arr = ft_split(s3, '\2');
	free(s3);
	return (arr);
}

/* FOR DEUGB USE: print_tokens(lst); */
int	sintax_errors(char *line)
{
	char		**tokens;
	t_token		*lst;

	lst = NULL;
	tokens = ft_lexerd(line);
	parser_tokens(&lst, tokens);
	free_arr(tokens);
	if (handle_pipe_err(lst))
		return (2);
	else if (handle_big_redir(lst))
		return (2);
	else if (handle_newline_err(lst))
		return (2);
	if (handle_quotes_err(lst))
		return (2);
	free_tokens(&lst);
	return (0);
}

int	msg_error(t_token *lst, char *type_err, int exit_status)
{
	data()->exit_status = 2;
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
