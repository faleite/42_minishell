/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:44:44 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/08 17:18:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*exit_value(char *s1)
{
	int		i;
	int		j;
	char	*s2;
	char	*s3;

	i = 0;
	j = 0;
	s2 = ft_itoa(data()->g_status);
	s3 = (char *)(malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!s3)
		return (NULL);
	while (s2[j])
		s3[i++] = s2[j++];
	while (*s1++)
		s3[i++] = *s1;
	s3[i] = '\0';
	free(s2);
	return (s3);
}

static int	print_dollar(char c)
{
	return (c == '/' || c == '.' || c == ',' || c == '%' || \
			c == ':' || c == '=' || c == ';' || c == ')' || \
			c == '+' || c == ']' || c == '}' || c == '!' || \
			c == '~' || c == '^' || c == '|');
}

int	dollar(char **src, char **dst, int i)
{
	char	*start;
	char	*end;
	char	*var;
	char	*value;

	start = ++(*src);
	while (**src != ' ' && **src != '\2' && **src != '\'' && \
			**src != '\"' && **src != '$' && !print_dollar(**src) && **src)
		(*src)++;
	end = *src;
	var = (char *)malloc(sizeof(char) * ((end - start) + 1));
	ft_strlcpy(var, start, ((end - start) + 1));
	if (var[0] == '?')
		value = exit_value(var);
	else
		value = get_value(var);
	if (value)
	{
		ft_strlcpy(*dst + i, value, (ft_strlen(*src) + ft_strlen(value) + 1));
		i += ft_strlen(value);
	}
	if (var[0] == '?')
		free(value);
	free(var);
	return (i);
}

int	inside_dbquotes(char **s1, char **s2, int i, char *sig)
{
	if (**s1 == '$' && *(*s1 + 1) != '\'' && !print_dollar(*(*s1 + 1)))
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
	if ((**s2 && **s2 == '$') && !print_dollar(*(*s2 + 1)))
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
