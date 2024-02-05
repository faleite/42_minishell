/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:47:32 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 16:33:57 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (size <= dstlen)
		return (size + srclen);
	dst += dstlen;
	while (i++ < (size - dstlen - 1) && *src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (dstlen + srclen);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main()
{
	char dst[100] = "1234";
	char src[100] = "AA";
	//size_t size = ft_strlen(dst);
	size_t size = 30;
	printf("ft_strlcat:\t%s\t%zu\n", dst, ft_strlcat(dst, src, size));
	printf("strlcat:\t%s\t%zu\n", dst, strlcat(dst, src, size));
}*/
