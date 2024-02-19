/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:41:05 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/18 21:45:32 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	have_quotes(char *s1);
static void	utils_strtrim(char **s1, char **s2);
static char	*handle_trim_quotes(char const *s1, int *val);

void	strtrim_quotes(char **arr)
{
	int		i;
	int		val;
	int		status;
	char	*tmp;

	i = 0;
	status = 0;
	if (arr && arr[i] && (!ft_strcmp(arr[i], "\"\"") || \
		!ft_strcmp(arr[i], "\'\'")))
		i++;
	while (arr && arr[i] != NULL)
	{
		val = 0;
		if (!have_quotes(arr[i]))
			i++;
		else
		{
			tmp = handle_trim_quotes(arr[i], &val);
			if (!(val % 2) && tmp)
				utils_strtrim(&arr[i], &tmp);
			else
				free(tmp);
			i++;
		}
	}
}

static void	utils_strtrim(char **s1, char **s2)
{
	free(*s1);
	*s1 = ft_strdup(*s2);
	free(*s2);
}

static int	have_quotes(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == '\"' || s1[i] == '\'')
			return (1);
		i++;
	}
	return (0);
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
