/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:15:32 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:52:12 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy and concatenate strings respectively. strlcat() take the full
 * size of the buffer (not just the length) and guarantee to NUL-terminate the
 * result (as long as there is at least one byte free in dst) For strlcat() both
 * src and dst must be NUL-terminated - The strlcat() appends the NUL-terminated
 * string src to the end of dst - It will append at most size - strlen(dst) - 1 
 * bytes, NUL-terminating the result.
 * @return the total length of the string they tried to create. that means the
 * initial length of dst plus the length of src.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize == 0 || dstsize < dst_len)
		return (src_len + dstsize);
	i = 0;
	while (src[i] && dstsize > (dst_len + i + 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
