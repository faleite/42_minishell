/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:44:44 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/17 20:29:40 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

// static int	outside_dbquotes(char **s1, char **s2, int i, char *sig)
static int	outside_dbquotes(char **s2, char **s3, int i)
{
	char	*start;
	char	*end;
	char	*var;
	char	*value;

	if (**s2 == '$')
	{
		if (*(*s2 + 1) == '\'' || *(*s2 + 1) == '\"')
			(*s2)++;
		else if (*(*s2 + 1) == ' ' || *(*s2 + 1) == '\0')
			(*s3)[i++] = *(*s2)++;
		else if (*(*s2 + 1) != ' ' && *(*s2 + 1) != '\0')
		{
			start = ++(*s2);
			while (**s2 != ' ' && **s2 != '\'' && **s2 != '\"' && **s2)
				(*s2)++;
			end = *s2;
			var = (char *)malloc(sizeof(char) * ((end - start) + 1));
			ft_strlcpy(var, start, ((end - start) + 1));
			value = getenv(var);
			if (value)
			{
				ft_strlcpy(*s3 + i, value, (ft_strlen(*s2) + ft_strlen(value) + 1));
				i += ft_strlen(value);
			}
			free (var);
		}
	}
	else
		(*s3)[i++] = *(*s2)++;
	return (i);
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
			if (*s2 == '\"' || *s2 == '\'')
				sig = 1;
			s3[i++] = *s2++;
		}
	}
	s3[i] = '\0';
	return (s3);
}

static void	aux_inside(int *i, char *sig, char **s1, char **s2)
{
	if (**s1 == '\"')
		*sig = 1;
	(*s2)[(*i)++] = *(*s1)++;
}

static int	inside_dbquotes(char **s1, char **s2, int i, char *sig)
{
	char	*start;
	char	*end;
	char	*var;
	char	*value;

	if (**s1 == '$' && *(*s1 + 1) != '\'')
	{
		start = ++(*s1);
		while (**s1 != ' ' && **s1 != '\'' && **s1 != '\"' && **s1)
			(*s1)++;
		end = *s1;
		var = (char *)malloc(sizeof(char) * ((end - start) + 1));
		ft_strlcpy(var, start, ((end - start) + 1));
		value = getenv(var);
		if (value)
		{
			ft_strlcpy(*s2 + i, value, (ft_strlen(*s1) + ft_strlen(value) + 1));
			i += ft_strlen(value);
		}
		free (var);
	}
	else
		aux_inside(&i, sig, s1, s2);
	return (i);
}

void	*expand_var(char *s1, char *s2)
{
	int		i;
	char	sig;

	i = 0;
	sig = 1;
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
}
