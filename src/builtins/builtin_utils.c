/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:37:04 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/05 03:18:52 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static int	is_num(char *str)
{
	int	flag;

	flag = 0;
	if (*str == '-')
		str++;
	while (*str)
	{
		flag = 1;
		if (!ft_isdigit(*str++))
			return (0);
	}
	if (flag)
		return (1);
	return (0);
}

int	is_long(char *str)
{
	int		len;
	char	pre;

	if (!is_num(str))
		return (0);
	pre = '\0';
	if (*str == '-')
		pre = *str++;
	len = ft_strlen(str);
	if (len > 20 || len < 1)
		return (0);
	if (len == 19)
	{
		if (ft_strncmp(str, "9223372036854775807", 20) > 0)
			return (0);
		if (ft_strncmp(str, "-9223372036854775808", 20) > 0)
			return (0);
	}
	return (1);
}
