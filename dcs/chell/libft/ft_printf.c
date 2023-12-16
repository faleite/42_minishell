/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:45:35 by anda-cun          #+#    #+#             */
/*   Updated: 2023/05/16 09:34:38 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_fs(va_list ap, char fs)
{
	if (fs == 'c')
		return (ft_putchar((unsigned char)va_arg(ap, int)));
	if (fs == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (fs == 'p')
		return (ft_ptr(va_arg(ap, long unsigned int), 16, fs));
	if (fs == 'd' || fs == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (fs == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int), 10, fs));
	if (fs == 'x')
		return (ft_putunbr(va_arg(ap, unsigned int), 16, fs));
	if (fs == 'X')
		return (ft_putunbr(va_arg(ap, unsigned int), 16, fs));
	if (fs == '%')
		return (ft_putchar('%'));
	return (0);
}

int	check_fs(char c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (!check_fs(str[i + 1]))
				len += ft_putchar(str[i++]);
			else
			{
				i++;
				len += write_fs(ap, str[i++]);
			}
		}
		else
			len += ft_putchar(str[i++]);
	}
	va_end(ap);
	return (len);
}
