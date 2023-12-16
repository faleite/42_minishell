/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:39:24 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/04 17:46:41 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	return (i);
}

/* int	main(void) */
/* { */
/* 	printf("%d\n", ft_putstr(NULL)); */
/* } */
