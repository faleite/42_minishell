/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:27:54 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/27 20:18:16 by faaraujo         ###   ########.fr       */
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
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 10));
	if (!s2)
		return (NULL);
	while (*s1)
	{
		if (sig == 1)
		{
			if (*s1 == '\"' || *s1 == '\'')
				sig = *s1;
			s2[i++] = *s1++;
		}
		else if (sig == '\'')
			i = inside_spquotes(&s1, &s2, i, &sig);
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
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s2) * 10));
	while (*s2)
	{
		if (sig == 1)
		{
			if (*s2 == '\"' || *s2 == '\'')
				sig = *s2;
			i = outside_quotes(&s2, &s3, i);
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

int	inside_spquotes(char **s1, char **s2, int i, char *sig)
{
	if (**s1 == '\'')
		*sig = 1;
	(*s2)[i++] = *(*s1)++;
	
	return (i);
}

int	inside_dbquotes(char **s1, char **s2, int i, char *sig)
{
	if (**s1 == '$' && *(*s1 + 1) != '\'')
		i = dollar(s1, s2, i);
	else
	{
		if (**s1 == '\"')
			*sig = 1;
		(*s2)[i++] = *(*s1)++;
	}
	return (i);
}

int	outside_quotes(char **s2, char **s3, int i)
{
	if (**s2 && **s2 == '$')
	{
		if (*(*s2 + 1) == '\"')
			(*s3)[i++] = *(*s2)++;
		else if (*(*s2 + 1) == '\'')
			(*s2)++;
		else if (*(*s2 + 1) == '\2' || *(*s2 + 1) == '\0')
			(*s3)[i++] = *(*s2)++;
		else if (*(*s2 + 1) != '\2' && *(*s2 + 1) != '\0')
			i = dollar(s2, s3, i);
	}
	else if (**s2)
		(*s3)[i++] = *(*s2)++;
	return (i);
}