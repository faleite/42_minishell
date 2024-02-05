/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:07:29 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 19:04:26 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_number(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (!ft_isdigit(*str) && *str != '+' && *str != '-')
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": numeric argument required", 2);
		data->exit_status = 2;
		return (data->exit_status);
	}
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(str, 2);
			ft_putendl_fd(": numeric argument required", 2);
			data->exit_status = 2;
			return (data->exit_status);
		}
	}
	return (0);
}

int	exit_builtin(t_data *data, char **str)
{
	unsigned char	ret;

	if (!str)
		data->exit = 0;
	if (!data->pipes.open)
	{
		ft_putendl_fd("exit", 2);
		data->exit = 1;
	}
	else
		data->exit = 0;
	if ((!str || !*str))
		return (data->exit_status);
	if (str[0] && str[1])
	{
		data->exit_status = 1;
		return (ft_putendl_fd("minishell: exit: too many arguments", 2));
		return (data->exit_status);
	}
	if (check_number(data, *str))
		return (0);
	ret = ft_atoi(str[0]);
	data->exit_status = ret;
	return (data->exit_status);
}
