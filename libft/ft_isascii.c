/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:45:56 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:14:17 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if "int c" is a ascii character
 * @param c Character to be checked
 * @return Returns zero if false, non-zero if true   
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
