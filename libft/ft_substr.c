/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:48:26 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:28:32 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string ’s’
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start >= s_len)
	{
		ss = (char *)malloc(sizeof(char));
		if (!(ss))
			return (NULL);
		ss[0] = '\0';
		return (ss);
	}
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ss))
		return (NULL);
	i = 0;
	while (len--)
		ss[i++] = s[start++];
	ss[i] = '\0';
	return (ss);
}
