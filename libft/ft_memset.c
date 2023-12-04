/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:51:13 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:30:40 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function fills the length of bytes (len) of the memory area pointed to
 * by dst with the constant byte c.
 * @param dst a pointer to the memory block to be filled.
 * @param c the value to be filled into the memory block. This value is
 * converted to an unsigned integer before being copied into memory.
 * @param len the number of bytes to pad.
 * @return a pointer to the memory area dst.
*/
void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dst;
	while (len--)
		*ptr++ = c;
	return (dst);
}
