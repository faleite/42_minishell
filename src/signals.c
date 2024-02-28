/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:26:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/27 21:26:05 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		data()->exit_status = 130;
		data()->h_flag = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		data()->signal = 0;
		data()->is_exec_all = 0;
	}
}

void	handle_sigint_hd(int sig)
{
	if (sig == SIGINT)
	{
		data()->exit_status = 130;
		data()->h_flag = 1;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		data()->signal = 0;
		data()->is_exec_all = 0;
	}
}

void	handle_crtl_pause(int sig)
{
	if (sig == SIGINT)
		return ;
}

void	handle_sigint_clean(int sig)
{
	(void) sig;
	clean_newline();
	close(data()->h_fd);
	exit(data()->exit_status);
}
