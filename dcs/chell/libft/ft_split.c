/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:48:32 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 19:05:17 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substr(char const *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**mainstr;

	j = 0;
	mainstr = (char **)malloc(sizeof(char *) * (count_substr(s, c) + 1));
	if (!mainstr)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		if (*s)
		{
			while (s[i] && s[i] != c)
				i++;
			mainstr[j] = ft_substr(s, 0, i);
			j++;
			s += i;
		}
	}
	mainstr[j] = NULL;
	return (mainstr);
}
/*
int	main()
{
	int	i = 0;
	char **str2 = ft_split("\0", ' ');
	//char **str2 = ft_split("gaaasdggggg", 'g');
	while (str2[i] != NULL)
		printf("%s\n", str2[i++]);
}*/
