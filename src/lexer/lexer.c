/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:32:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/05 17:42:12 by faaraujo         ###   ########.fr       */
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
	char	**arr;

	arr = NULL;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 2 + 1));
	if (!s2)
		return (NULL);
	handle_quotes(s1, s2);
	replace_spaces(s2);
	s3 = expander_outside(s2);
	free(s2);
	s4 = expander_inside(s3);
	free(s3);
	arr = ft_split(s4, '\2');
	arr = strtrim_quotes(arr);
	free(s4);
	return (arr);
}

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i++]);
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i++]);
	}
	free(arr);
}
