/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:30:59 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:37:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief function allocates memory for an array of nbrs elements of size bytes
 * each and returns a pointer to the allocated memory
 * The memory is set to zero
 * If nbrs or size is 0, then calloc() returns either NULL, or a unique pointer
 * value that can later be successfully passed to free()
 * If the multiplication of nbrs and size would result in integer overflow, then
 * calloc() returns an error
 * By contrast, an integer overflow would not be detected in the following call
 * to malloc(), with the result that an incorrectly sized block of memory would
 * be allocated: malloc(nmemb * size);
 * @param nthings numbers of things to allocate
 * @param size length in bytes to each things
 * @return a pointer to the allocated memory, which is suitably aligned for any
 * built-in type. On error, these functions return NULL.
*/
void	*ft_calloc(size_t nthings, size_t size)
{
	size_t	t_size;
	size_t	*ptr;

	t_size = nthings * size;
	ptr = (size_t *)malloc(t_size);
	if (!(ptr))
		return (NULL);
	ft_memset(ptr, 0, t_size);
	return ((void *)ptr);
}
