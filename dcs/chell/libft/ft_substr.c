/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:11:59 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 15:11:02 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlen;
	char	*substr;

	i = 0;
	strlen = ft_strlen(s);
	if (start >= strlen)
		len = 0;
	else if (strlen - start < len)
		len = strlen - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (len--)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
/*
#include <stdio.h>
int	main()
{
	char *str = "aeioua";
	unsigned int start = 6;
	size_t len = 10;
	char *substr = ft_substr("hola", 42946295, 0);
	printf("%s\n", substr);
}*/
