/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:41:13 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 18:32:53 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	if ((!dest && !src) || dest == src)
		return (dest);
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	i = 0;
	if (cdest > csrc)
		while (n--)
			cdest[n] = csrc[n];
	else
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (cdest);
}
/*
#include <stdio.h>
int	main()
{
	char str1[100] = "aeiou";
	char str2[100] = "aeiou";
	char	*dest1 = str1 + 9;
	char	*dest2 = str2 + 9;

	size_t	n = 10 * sizeof(char);
	(char *)ft_memmove(dest1, str1, n);
	(char *)memmove(dest2, str2, n);
	printf("ft_memmove:\t%s\n", dest1);
	printf("memmove:\t%s\n", dest2);
}*/
