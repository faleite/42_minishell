/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:27:08 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/08 17:12:41 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exit_final(t_command *command)
{
	free_struct(command);
	free_envp(data()->envp);
	clear_history();
	exit(data()->g_status);
}

int	exit_cmd_null(t_command *command)
{
	free_struct(command);
	free_envp(data()->envp);
	clear_history();
	printf("exit\n");
	exit(data()->g_status);
}
