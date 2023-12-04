/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:05:55 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:36:14 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c (converted	to an unsigned char) in
 * string s.
 * @return a pointer to the byte located, or NULL if no such byte exists within
 * len bytes.
*/
void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*s_cpy;
	unsigned char	c_cpy;

	s_cpy = (unsigned char *)s;
	c_cpy = (unsigned char)c;
	while (len--)
	{
		if (*s_cpy == c_cpy)
			return (s_cpy);
		s_cpy++;
	}
	return (NULL);
}
