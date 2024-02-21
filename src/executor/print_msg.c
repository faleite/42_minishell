/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:26:06 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/21 17:33:27 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	command_error(t_command *command)
{
	if (ft_strcmp(command->args[0], "\3"))
	{
		ft_putstr_fd(command->args[0], STDERR_FILENO);
		ft_putendl_fd(" command not found!", STDERR_FILENO);
	}
}
