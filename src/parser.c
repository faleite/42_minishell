/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/05 03:34:24 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/*
* DEBUGS:
* print_args(args);
* print_redirects(redirect);
* print_prompt(prompt);
*
* EXECUTOR:
* init_exec(prompt); // Put in line 43
*
* ATTENTION:
* delete fct print_prompt() at the line 46
* call free_prompt() after fill struct executor
*/
void	exec_process(t_prompt *prompt, char **envp)
{
	t_command	*exec;
	t_envp		*getev;

	getev = NULL;

	fill_envp(&getev, envp);
	var_path(getev);
	//print_envp(getev);

	data()->envp = getev;
	// print_envp(data()->envp);

	// Builtins
	// ft_env(getev);
	// ft_export(&getev, curr->args);
	exec = init_exec(prompt);

	ft_open_all(exec);
	executing(exec);
}

void	init_process(char *line, char **envp)
{
	char		**tokens;
	t_args		*args;
	t_redirect	*redirect;
	t_prompt	*prompt;
	t_command	*exec;

	tokens = ft_lexer(line);
	handle_heredoc(tokens);
	strtrim_quotes(tokens);
	args = NULL;
	parser_args(&args, tokens);
	redirect = NULL;
	parser_redirects(&redirect, tokens);
	prompt = NULL;
	parser_prompt(&prompt, args, redirect, tokens);
	free_args(&args);
	free_redirects(&redirect);
	free_arr(tokens);
	exec = init_exec(prompt);
	ft_open_all(exec);
	exec_process(prompt, envp);
	// print_commands(exec);
	//print_prompt(prompt);
	//free_prompt(&prompt);
}

void	cmdline(char *cmd_line, char **envp)
{
	int	i;

	i = 1;
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
			{
				add_history(cmd_line);
				if (!sintax_errors(cmd_line))
					init_process(cmd_line, envp);
			}
		}
		free(cmd_line);
		cmd_line = NULL;
	}
}


/* JUST DEBUG FOR PARSER */
int	main(int ac, char *av[], char *envp[])
{
	char	*cmd_line; 

	cmd_line = NULL;
	cmdline(cmd_line, envp);
	return (0);
}
