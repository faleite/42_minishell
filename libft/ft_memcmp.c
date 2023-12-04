/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:47:20 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:19:01 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief function compares the first n bytes (each interpreted as unsigned
 * char) of the memory areas s1 and s2.
 * @return function returns zero if the two strings are identical, otherwise
 * returns the difference between the first two differing bytes (treated as
 * unsigned char values, so that `\200' is greater than `\0', for example).
 * Zero-length strings are always identical.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (len--)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
