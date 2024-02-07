/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:25:43 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/07 12:26:23 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
*/
int		ft_putstr_fd(char *s, int fd)
{
	if (write(fd, s, ft_strlen(s)) == -1)
		return (-1);
	return (0);
}
