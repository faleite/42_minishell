/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:32:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/25 11:08:40 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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
	s2 = split_pipes(s1);
	s3 = split_redirects(s2);
	free(s2);
	replace_spaces(s3);
	s4 = expander_outside(s3);
	free(s3);
	s5 = expander_inside(s4);
	free(s4);
	arr = ft_split(s5, '\2');
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

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr && arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}