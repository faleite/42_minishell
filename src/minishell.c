/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/08 19:52:17 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

//<<Makefile cat| echo "$PWD <$?> | 'hola'" "$HOME"/src | echo $? '$?' |'tr' -d / >outfile

void	init_process(char *line)
{
	char		**tokens;
	t_prompt	*prompt;

	prompt = NULL;
	tokens = ft_lexer(line);
	//printf("%d\n", cmds_size(prompt->redirect));
	ft_parser(&prompt, tokens);
	//prompt->redirect = fill_data_redirect(tokens);
	//printf("%d\n", cmds_size(prompt));
	print_prompt(prompt);
	//print_redirects(prompt->redirect);
	//print_arr(tokens);
	free_arr(tokens);
	//free_redirects(&(prompt->redirect));
	//free(prompt);
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

/*
lexer problem
<file|<file2:
<
file
|<
file2
*/
int	main(void)
{
	char	*cmd_line;

	cmd_line = NULL;
	cmdline(cmd_line);
	return (0);
}
