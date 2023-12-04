/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 10:21:29 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:21:42 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief function locates the last occurrence of c (converted to a char) in the
 * string pointed to by s
 * The terminating null character is considered part of the string; therefore if
 * c is `\0', the functions locate the terminating `\0'.
 * @param s Pointer of string.
 * @param c character to be found (converted to char).
 * @return a pointer to the located character, or NULL if the character does not
 * appear in the string. The terminating null byte is considered part of the 
 * string.
*/
char	*ft_strrchr(const char *s, int c)
{
	const char	*s_last;

	s_last = s;
	if (c > 127)
		c %= 256;
	while (*s_last)
		s_last++;
	while (s_last != s)
	{
		if (*s_last == c)
			return ((char *)s_last);
		s_last--;
	}
	if (*s_last == c)
		return ((char *)s_last);
	return (NULL);
}
