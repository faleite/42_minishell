/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:06:47 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 18:34:35 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	int				i;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while (n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		n--;
		i++;
	}
	return (0);
}
/*
int	main()
{
	printf("%d\t", ft_memcmp(".........", ".........", 10));
	printf("%d\t", memcmp(".........", ".........", 10));
}*/
