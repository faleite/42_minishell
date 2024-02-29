/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:27:08 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/29 15:57:32 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exit_final(void)
{
	clean_newline();
	clear_history();
	exit(data()->exit_status);
	return (0);
}

int	clean_newline(void)
{
	fuck_fds();
	free_arr(getevarr()->envp);
	free_struct(data()->exec);
	free_envp(data()->envp);
	return (0);
}

int	exit_finald(void)
{
	free_arr(getevarr()->envp);
	free_envp(data()->envp);
	clear_history();
	ft_putendl_fd("exit", 1);
	exit(data()->exit_status);
	return (0);
}

void	unlink_heredoc(void)
{
	if (access("/tmp/heredoc_file", F_OK) == 0)
		unlink("/tmp/heredoc_file");
}
