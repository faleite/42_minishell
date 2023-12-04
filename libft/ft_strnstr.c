/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:39:30 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:22:46 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strnstr() function locates the	first occurrence of the
 * null-terminated string little in the	string big, where not more than	len
 * characters are searched
 * Characters that appear after a `\0' character are not searched
 * Since the strnstr() function is a FreeBSD specific API, it should only be
 * used when portability is not a concern.
 * @return If little is an empty string, big is returned; if little occurs
 * nowhere in big, NULL is returned; otherwise a pointer to the first character 
 * of the first occurrence of little is returned.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!(*little))
		return ((char *)big);
	little_len = ft_strlen(little);
	i = 0;
	while (*big && (i < len))
	{
		if ((ft_strncmp(big, little, little_len) == 0)
			&& (i + little_len <= len))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
