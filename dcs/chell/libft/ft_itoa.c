/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:28:41 by anda-cun          #+#    #+#             */
/*   Updated: 2023/07/07 09:40:07 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nsize(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 1;
	else
	{
		while (n)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}

static int	isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
	int		number;

	size = nsize(n) + isneg(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (isneg(n))
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		number = (n % 10);
		if (number < 0)
			number *= -1;
		str[--size] = number + '0';
		n /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("result: %s\n", ft_itoa(-2147483648));
	//printf("result: %s\n", ft_itoa(-21474848));
}*/
