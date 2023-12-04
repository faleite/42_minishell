/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:49:13 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:23:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strdup() function returns a pointer to a new string which is a
 * duplicate of the string s
 * Memory for the new string is obtained with malloc(3), and can be freed with
 * free(3).
 * @return On success, the strdup() function returns a pointer to the duplicated
 * string. It returns NULL if insufficient memory was available, with errno set 
 * to indicate the cause of the error.
 * @attention ERRORS --> ENOMEM Insufficient memory available to allocate 
 * duplicate string.
*/
char	*ft_strdup(const char *s)
{
	char	*s_dup;
	int		len;

	len = ft_strlen(s);
	s_dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s_dup))
		return (NULL);
	while (*s)
		*s_dup++ = *s++;
	*s_dup = '\0';
	return (s_dup - len);
}
