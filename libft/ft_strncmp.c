/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:18:08 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/02 21:17:17 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief compares only the first (at most) n bytes of s1 and s2. 
 * @param s1 Pointer of string.
 * @param s2 Pointer of string.
 * @param n for comparing len characters
 * @return an integer greater than, equal to, or less than 0, according as the
 * string s1 is greater than, equal to, or less than the string s2
 * The comparison is done using unsigned characters, so that `\200' is greater
 * than `\0'.
*/
// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*cs1;
// 	unsigned char	*cs2;

// 	cs1 = (unsigned char *)s1;
// 	cs2 = (unsigned char *)s2;
// 	i = 0;
// 	while ((cs1[i] || cs2[i]) && i < n)
// 	{
// 		if (cs1[i] != cs2[i])
// 			return (cs1[i] - cs2[i]);
// 		i++;
// 	}
// 	return (0);
// }
int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-1);
	while ((s1[i] || s2[i]) && (i < num))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
