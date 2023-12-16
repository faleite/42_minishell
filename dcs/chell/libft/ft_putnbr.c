/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:17:16 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/04 17:46:59 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i = ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			i += ft_putchar('-');
			n *= -1;
		}
		if (n < 10)
			i += ft_putchar(n + '0');
		else
		{
			i += ft_putnbr(n / 10);
			i += ft_putnbr(n % 10);
		}
	}
	return (i);
}
/* int	main(void) */
/* { */
/* 	int	i; */

/* 	i = ft_putnbr(-2147483648); */
/* 	printf("\n%d\n", i); */
/* 	/1* ft_putchar('\n'); *1/ */
/* 	/1* ft_putnbr(-21); *1/ */
/* 	/1* ft_putchar('\n'); *1/ */
/* 	/1* ft_putnbr(0); *1/ */
/* } */
