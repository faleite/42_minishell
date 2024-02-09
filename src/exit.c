/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:27:08 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/09 19:18:37 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exit_final(void)
{
	free_struct(data()->exec);
	free_envp(data()->envp);
	free_arr(getevarr()->envp);
	clear_history();
	exit(data()->exit_status);
	return (0);
}

// int	exit_cmd_null(t_command *command)
// {
// 	free_struct(command);
// 	free_envp(data()->envp);
// 	free_arr(getevarr()->envp);
// 	clear_history();
// 	printf("exit\n");
// 	exit(data()->exit_status);
// }
