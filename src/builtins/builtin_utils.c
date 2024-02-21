/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:37:04 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/21 16:30:39 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_num(char *str)
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
	return (flag);
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

int	in_str(char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			flag = 1;
		i++;
	}
	return (flag);
}
