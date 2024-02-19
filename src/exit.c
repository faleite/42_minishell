/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:27:08 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/19 18:23:58 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exit_final(void)
{
	free_arr(getevarr()->envp);
	free_struct(data()->exec);
	free_envp(data()->envp);
	clear_history();
	free(data()->heredoc_path);
	exit(data()->exit_status);
	return (0);
}

int	clean_newline(void)
{
	free_arr(getevarr()->envp);
	free_struct(data()->exec);
	free_envp(data()->envp);
	free(data()->heredoc_path);
	return (0);
}

int	exit_finald(void)
{
	free_arr(getevarr()->envp);
	free_envp(data()->envp);
	clear_history();
	ft_putendl_fd("exit", 1);
	free(data()->heredoc_path);
	exit(data()->exit_status);
	return (0);
}

void	unlink_heredoc(void)
{
	if (access(data()->heredoc_path, F_OK) == 0)
		unlink(data()->heredoc_path);
}
