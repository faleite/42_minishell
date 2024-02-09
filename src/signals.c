/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:26:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/09 19:25:13 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	new_prompt(void)
{
	rl_reset_line_state();
	rl_cleanup_after_signal();
	rl_replace_line("", 0);
	rl_crlf();
	//rl_redisplay();
}

void handle_sigint(int sig) 
{
	if (sig && data()->exit_status == 0)
		new_prompt();
	else if (sig)
		printf("\n");
}

void heredoc_handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		data()->exit_status = -10;
	}
}
