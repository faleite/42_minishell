/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:26:06 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/22 18:51:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	command_error(t_command *command)
{
	if (command && command->args[0])
	{
		ft_putstr_fd(command->args[0], STDERR_FILENO);
		ft_putendl_fd(" command not found!", STDERR_FILENO);
	}
}
