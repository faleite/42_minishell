/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/05 22:07:54 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	init_process(char *line)
{
	char		**tokens;
	t_redirect	*redirect;

	tokens = ft_lexer(line);
	redirect = fill_data_redirect(tokens);
	printf("%d\n", cmds_size(redirect));
	print_redirects(redirect);
	//print_arr(tokens);
	free_arr(tokens);
}

void	cmdline(char *cmd_line)
{
	while (1)
	{
		if (!cmd_line)
			cmd_line = readline("[minishell]$ ");
		if (!cmd_line)
		{
			printf("exit\n");
			break ;
		}
		else
		{
			if (*cmd_line)
				add_history(cmd_line);
			init_process(cmd_line);
		}
		free(cmd_line);
		cmd_line = NULL;
		g_status = 0;
	}
}

int	main(void)
{
	char	*cmd_line;

	cmd_line = NULL;
	cmdline(cmd_line);
	return (0);
}
