/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:20:17 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/15 17:13:36 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required", 2);
}

int	exit_builtin(t_command *command)
{
	data()->exit_status = 0;
	if (command->args[1])
	{
		if (command->args[2])
		{
			ft_putendl_fd("minishell: exit: too many arguments", 2);
			return (1);
		}
		if (!is_long(command->args[1]))
		{
			data()->exit_status = 2;
			print_error(command->args[1]);
		}
		else if (!command->args[2])
			data()->exit_status = ft_atoi(command->args[1]);
	}
	return (exit_final());
}
