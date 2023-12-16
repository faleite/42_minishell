/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:19:05 by eportela          #+#    #+#             */
/*   Updated: 2023/10/10 13:23:58 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	terminal_prompt(void)
{
	rl_reset_line_state();
	rl_cleanup_after_signal();
	rl_replace_line("", 0);
	rl_crlf();
	rl_redisplay();
}

void	sigint_handler(int signal)
{
	if (signal && g_signal == 0)
		terminal_prompt();
	else if (signal)
		printf("\n");
}

void	heredoc_sigint_handler(int signal)
{
	if (signal)
	{
		printf("\n");
		g_signal = -10;
	}
}
