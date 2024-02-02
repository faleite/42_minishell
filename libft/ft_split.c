/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:39:15 by feden-pe          #+#    #+#             */
/*   Updated: 2023/04/20 16:38:14 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

static char	*word_cpy(const char *s, char **list, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	*list = ft_substr(s, 0, i);
	return ((char *)s + i);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	char	**split;

	if (!s)
		return (NULL);
	list = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!list)
	{
		free(list);
		return (NULL);
	}
	split = list;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			s = word_cpy(s, list++, c);
	}
	*list = 0;
	return (split);
}
