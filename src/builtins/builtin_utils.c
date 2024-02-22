/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:37:04 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/22 19:01:56 by feden-pe         ###   ########.fr       */
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
	int		i;

	len = ft_strlen(str);
	i = 0;
	if (len > 20 || len < 1)
		return (0);
	if (len == 19)
	{
		if (ft_strncmp(str, "9223372036854775807", 20) > 0)
			return (0);
		if (ft_strncmp(str, "-9223372036854775808", 20) > 0)
			return (0);
	}
	if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
	{
		data()->exit_status = 2;
		return (0);
	}
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
		{
			data()->exit_status = 2;
			return (0);
		}
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
