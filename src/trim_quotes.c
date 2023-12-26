/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:41:05 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/26 21:43:41 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char	*handle_trim_quotes(char const *s1)
{
	char	*s2;
	char	*start_s2;
	int		val;
	char	sig;

	val = 0;
	sig = '\1';
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	start_s2 = s2;
	while (*s1)
	{
		if (sig == '\1' && (*s1 == '\"' || *s1 == '\''))
		{
				sig = *s1;
				s1++;
		}
		else if (*s1 == sig)
		{
			sig = '\1';
			s1++;
		}
		else
			*s2++ = *s1++;
	}
	*s2 = '\0';
	return (start_s2);
}

char	**strtrim_quotes(char **arr)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (arr[i] && arr)
	{

		tmp = handle_trim_quotes(arr[i]);
		if (tmp)
		{
			free(arr[i]);
			arr[i] = tmp;
		}
		i++;
	}
	return (arr);
}
