/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:26:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/21 18:54:33 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sigint(int sig)
{
	t_command	*current;

	if (sig == SIGINT)
	{
		data()->exit_status = 130;
		data()->h_flag = 1;
		if (data()->signal == 1)
			write(STDIN_FILENO, "\n", 1);
		else
			ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		data()->signal = 0;
		current = data()->exec;
		while (current)
		{
			current->is_exec = 0;
			current = current->next;
		}
	}
}

void	handle_sigint_clean(int sig)
{
	clean_newline();
	close(data()->h_fd);
	exit(data()->exit_status);
}
