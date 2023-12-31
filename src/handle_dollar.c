/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:44:44 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/31 12:48:45 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	g_status;

char	*exit_value(char *s1)
{
	int		i;
	int		j;
	char	*s2;
	char	*s3;

	i = 0;
	j = 0;
	g_status = 127;
	s2 = ft_itoa(g_status);
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

int	dollar(char **src, char **dst, int i)
{
	char	*start;
	char	*end;
	char	*var;
	char	*value;

	start = ++(*src);
	while (**src != ' ' && **src != '\2' && **src != '\'' && \
			**src != '\"' && **src)
		(*src)++;
	end = *src;
	var = (char *)malloc(sizeof(char) * ((end - start) + 1));
	ft_strlcpy(var, start, ((end - start) + 1));
	if (var[0] == '?')
		value = exit_value(var);
	else
		value = getenv(var);
	if (value)
	{
		ft_strlcpy(*dst + i, value, (ft_strlen(*src) + ft_strlen(value) + 1));
		i += ft_strlen(value);
	}
	if (var[0] == '?')
		free(value);
	free (var);
	return (i);
}
