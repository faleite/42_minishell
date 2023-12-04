/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:19:23 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/20 11:18:31 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The atoi() function converts the initial portion of the string pointed
 * to by nptr to int representation.
 * @return The converted value.
*/
int	ft_atoi(const char *ptr)
{
	int	i;
	int	pn;
	int	nbr;

	i = 0;
	pn = 1;
	nbr = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			pn = -1;
		i++;
	}
	while (ptr[i] && ft_isdigit(ptr[i]))
	{
		nbr *= 10;
		nbr += ptr[i] - 48;
		i++;
	}
	return (nbr * pn);
}
