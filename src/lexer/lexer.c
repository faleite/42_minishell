/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:32:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/20 22:33:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Substitui separador
 * echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * echo/2"hello      there"/2how/2are/2'you 'doing?/2$USER/2|wc/2-l/2>outfile
*/
char	**ft_lexer(char *s1)
{
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;
	char	**arr;

	arr = NULL;
	s2 = str_spaces_end(s1);
	s3 = split_pipes(s2);
	free(s2);
	s2 = split_redirects(s3);
	free(s3);
	replace_spaces(s2);
	s4 = expander_outside(s2);
	free(s2);
	s5 = expander_inside(s4);
	free(s4);
	arr = ft_split(s5, '\2');
	space_end(arr);
	free(s5);
	return (arr);
}

char	*split_redirects(char *s1)
{
	char	*s2;

	s2 = ft_calloc((ft_strlen(s1) * 2 + 1), sizeof(char));
	handle_redirects(s1, s2);
	replace_spaces(s2);
	return (s2);
}

char	*split_pipes(char *s1)
{
	char	*s2;

	s2 = ft_calloc((ft_strlen(s1) * 2 + 1), sizeof(char));
	handle_pipe(s1, s2);
	replace_spaces(s2);
	return (s2);
}

void	space_end(char **tokens)
{
	int	i;
	int	len;

	i = 0;
	while (tokens[i])
		i++;
	i--;
	len = ft_strlen(tokens[i]) - 1;
	if (tokens[i] && !ft_strcmp(tokens[i], " "))
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	else if (tokens[i] && tokens[i][len] == ' ')
		tokens[i][len] = '\0';
}
