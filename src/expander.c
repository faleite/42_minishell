/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:27:54 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/22 21:31:11 by faaraujo         ###   ########.fr       */
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

char	*cmd_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*s2;
	int		val;

	val = -1;
	if (!(s1))
		return (NULL);
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return(NULL);
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
	return (s2);
}

char	**strtrim_quotes(char **arr)
{
	size_t	i;
	char	*duo;
	char	*uno;
	char	*tmp;

	tmp = NULL;
	duo = "\"";
	uno = "\'";
	i = 0;
	while (arr[i] && arr)
	{
		tmp = cmd_strtrim(arr[i], duo);
        if (tmp)
        {
            free(arr[i]);
            arr[i] = tmp;
        }
        tmp = cmd_strtrim(arr[i], uno);
        if (tmp)
        {
            free(arr[i]);
            arr[i] = tmp;
        }
        i++;
	}
	return (arr);
}
