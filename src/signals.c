/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:26:00 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/07 20:48:17 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	new_prompt(void)
{
	rl_reset_line_state();
	rl_cleanup_after_signal();
	rl_replace_line("", 0);
	rl_crlf();
	// rl_redisplay();
}

void handle_sigint(int sig) 
{
	if (sig && data()->g_status == 0)
		new_prompt();
	else if (sig)
		printf("\n");
}

void heredoc_handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		data()->g_status = -10;
	}
}
