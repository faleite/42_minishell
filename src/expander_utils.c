/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:44:44 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/18 21:27:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	dollar(char **src, char **dst, int i);
static void	aux_inside(int *i, char *sig, char **s1, char **s2);

int	inside_dbquotes(char **s1, char **s2, int i, char *sig)
{
	if (**s1 == '$' && *(*s1 + 1) != '\'')
		i = dollar(s1, s2, i);
	else
		aux_inside(&i, sig, s1, s2);
	return (i);
}

int	outside_dbquotes(char **s2, char **s3, int i)
{
	if (**s2 == '$')
	{
		if (*(*s2 + 1) == '\"')
			(*s3)[i++] = *(*s2)++;
		else if (*(*s2 + 1) == '\'')
			(*s2)++;
		else if (*(*s2 + 1) == ' ' || *(*s2 + 1) == '\0')
			(*s3)[i++] = *(*s2)++;
		else if (*(*s2 + 1) != ' ' && *(*s2 + 1) != '\0')
			i = dollar(s2, s3, i);
	}
	else
		(*s3)[i++] = *(*s2)++;
	return (i);
}


static void	aux_inside(int *i, char *sig, char **s1, char **s2)
{
	if (**s1 == '\"')
		*sig = 1;
	(*s2)[(*i)++] = *(*s1)++;
}

static int	dollar(char **src, char **dst, int i)
{
	char	*start;
	char	*end;
	char	*var;
	char	*value;

	start = ++(*src);
	while (**src != ' ' && **src != '\'' && **src != '\"' && **src)
		(*src)++;
	end = *src;
	var = (char *)malloc(sizeof(char) * ((end - start) + 1));
	ft_strlcpy(var, start, ((end - start) + 1));
	value = getenv(var);
	if (value)
	{
		ft_strlcpy(*dst + i, value, (ft_strlen(*src) + ft_strlen(value) + 1));
		i += ft_strlen(value);
	}
	free (var);
	return (i);
}
