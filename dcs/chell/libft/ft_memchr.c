/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:10:16 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 18:35:41 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n--)
		if (*(s1++) == (unsigned char) c)
			return (--s1);
	return (NULL);
}
/*
int	main()
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
//	char	*s = "Hello";
//	char	c = 'e';
	size_t n = 7;
	printf("%s\n", (char *)ft_memchr(tab, -1, n));
	printf("%s\n", (char *)memchr(tab, -1, n));
}*/
