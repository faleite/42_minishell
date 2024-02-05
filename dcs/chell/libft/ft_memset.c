/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:02:48 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 15:19:28 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*ptr;

	ptr = s;
	while (n--)
		*((unsigned char *)s++) = c;
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	int	i = 0;
//	int str[] = {1, 2, 3, 4, 5};
//	int str2[] = {1, 2, 3, 4, 5};
	char str[] = "Hello";
	char str2[] = "Hello";

	ft_memset(str, 1, 3*sizeof(char));
	memset(str2, 1, 3*sizeof(char));
	i = 0;
	while (i < 5)
	{
		printf("%p\t", str[i]);
		printf("%d\t", str[i]);
		printf("%p\t", str2[i]);
		printf("%d\n", str2[i++]);
	}
}*/
