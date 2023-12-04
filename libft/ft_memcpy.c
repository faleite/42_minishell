/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:48:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:32:21 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The memcpy() function copies len bytes from string src to string dst.
 * If src and dst overlap, the results are not defined.
 * @return The memcpy() function returns the original value of dst.
*/
void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (dst == NULL && src == NULL)
		return (NULL);
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	while (len--)
		*s2++ = *s1++;
	return (dst);
}
