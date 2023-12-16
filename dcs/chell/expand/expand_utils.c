/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:38:42 by eportela          #+#    #+#             */
/*   Updated: 2023/10/10 13:06:32 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	should_break(t_arg *arg, int i)
{
	if (arg->token[i] == '\"' || arg->token[i] == '\'' || arg->token[i] == ' ')
		return (1);
	return (0);
}

char	*c_strdup(const char *s, char *freeit)
{
	char	*str;
	int		length;
	int		i;

	length = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (length + 1));
	i = -1;
	free(freeit);
	if (!str)
		return (NULL);
	while (s && s[++i])
		str[i] = s[i];
	str[length] = '\0';
	return (str);
}

char	*c_strjoin(char *str, char *s)
{
	int		i;
	int		j;
	char	*result;

	i = -1;
	j = 0;
	if (!str)
		result = ft_strdup(s);
	else if (!s)
		result = ft_strdup(str);
	else
	{
		result = malloc(ft_strlen(str) + ft_strlen(s) + 1);
		while (str[++i] != '\0')
			result[j++] = str[i];
		i = -1;
		while (s[++i] != '\0')
			result[j++] = s[i];
		result[j] = '\0';
	}
	free(str);
	if (s != NULL)
		free(s);
	return (result);
}

char	*ft_append(char *s, char c)
{
	char	*temp;
	int		i;

	temp = malloc(ft_strlen(s) + 2);
	i = -1;
	while (s[++i] != '\0')
		temp[i] = s[i];
	temp[i++] = c;
	temp[i] = '\0';
	free(s);
	return (temp);
}

int	parse(char **trying, int i, char *flag)
{
	if (*flag)
	{
		if (trying[i][0] != *flag)
			return (1);
		else
		{
			*flag = 0;
			return (0);
		}
	}
	else
	{
		if (trying[i][0] == '\"' || trying[i][0] == '\'')
		{
			*flag = trying[i][0];
			return (0);
		}
		else
			return (1);
	}
}
