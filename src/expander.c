/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:27:54 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/24 14:05:00 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

char	*expander_inside(char *s1)
{
	int		i;
	char	sig;
	char	*s2;

	i = 0;
	sig = 1;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 2));
	if (!s2)
		return (NULL);
	while (*s1)
	{
		if (sig == 1)
		{
			if (*s1 == '\"')
				sig = *s1;
			s2[i++] = *s1++;
		}
		else
			i = inside_dbquotes(&s1, &s2, i, &sig);
	}
	s2[i] = '\0';
	return (s2);
}

char	*expander_outside(char *s2)
{
	int		i;
	char	sig;
	char	*s3;

	i = 0;
	sig = 1;
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s2) * 2));
	while (*s2)
	{
		if (sig == 1)
		{
			if (*s2 == '\"' || *s2 == '\'')
				sig = *s2;
			i = outside_dbquotes(&s2, &s3, i);
		}
		else
		{
			if (*s2 == sig)
				sig = 1;
			s3[i++] = *s2++;
		}
	}
	s3[i] = '\0';
	return (s3);
}

static char	*handle_trim_quotes_aux(int val, char *ptr)
{
	if (val != 2)
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

char	*handle_trim_quotes(char const *s1, char const *set)
{
	char	*s2;
	char	*start_s2;
	int		val;

	val = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	start_s2 = s2;
	while (*s1)
	{
		if (*s1 != *set)
			*s2++ = *s1++;
		else
		{
			s1++;
			val++;
		}
	}
	*s2 = '\0';
	return (handle_trim_quotes_aux(val, start_s2));
}

void	aux(char **ptr, char **str)
{
	free(*str);
	*str = *ptr;
}

char	first_quote(char *str)
{
	int	i;
	int	duo;
	int	uno;

	i = 0;
	duo = 0;
	uno = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			duo = i;
		if (str[i] == '\'')
			uno = i;
		i++;
	}
	if (duo > uno)
		return ('\"');
	if (uno > duo)
		return ('\'');
	return ('0');
}

char	**strtrim_quotes(char **arr)
{
	size_t	i;
	char	*duo;
	char	*uno;
	char	*tmp;

	duo = "\"";
	uno = "\'";
	tmp = NULL;
	i = 0;
	while (arr[i] && arr)
	{
		if (first_quote(arr[i]) == *duo)
		{
			tmp = handle_trim_quotes(arr[i], duo);
			aux(&tmp, &arr[i]);
		}
		else if (first_quote(arr[i]) == *uno)
		{
			tmp = handle_trim_quotes(arr[i], uno);
			aux(&tmp, &arr[i]);
		}
		i++;
	}
	return (arr);
}
