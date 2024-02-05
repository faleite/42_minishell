/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:39:42 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 18:34:52 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	void	*ptr;

	if ((!dest && !src) || dest == src)
		return (dest);
	ptr = dest;
	while (size--)
		*((unsigned char *)ptr++) = *((unsigned char *)src++);
	return (dest);
}
/*
int	main()
{
	char	*dest = "\0";
	char	*src = dest;

	ft_memcpy(dest, src, 2*sizeof(char));
//	memcpy(dest, src, 2*sizeof(char));
	printf("dest is %s\n", dest);
}*/
