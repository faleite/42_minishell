/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:41:05 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/27 17:45:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char	*handle_trim_quotes(char const *s1, int *val);

char	**strtrim_quotes(char **arr)
{
	int		i;
	int		val;
	char	*tmp;

	i = 0;
	while (arr[i] && arr)
	{
		val = 0;
		tmp = handle_trim_quotes(arr[i], &val);
		if (!(val % 2) && tmp)
		{
			free(arr[i]);
			arr[i] = tmp;
		}
		else
		 	free(tmp);
		i++;
	}
	return (arr);
}

static char	*handle_trim_quotes(char const *s1, int *val)
{
	char	*s2;
	char	sig;
	int		i;

	sig = '\1';
	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	while (*s1)
	{
		if (sig == '\1' && (*s1 == '\"' || *s1 == '\''))
		{
			sig = *s1++;
			(*val)++;
		}
		else if (*s1 == sig)
		{
			sig = '\1';
			s1++;
			(*val)++;
		}
		else
			s2[i++] = *s1++;
	}
	s2[i] = '\0';
	return (s2);
}
