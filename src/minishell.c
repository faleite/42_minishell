/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/23 21:34:29 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <linux/limits.h>
#include <unistd.h>

/**
* DEBUGS:
* print_args(args);
* print_redirects(redirect);
* print_prompt(prompt);
* print_commands(exec);
* print_prompt(exec->prompt);
*
* EXECUTOR:
* free_envp(data()->envp);
* free_arr(getevarr()->envp);
*/
void	exec_process(t_prompt *prompt, char **envp)
{
	t_command	*exec;

	data()->is_exec_all = 1;
	data()->path = get_value("PATH");
	data()->h_flag = 0;
	exec = init_exec(prompt);
	data()->exec = exec;
	ft_open_all(exec);
	executing(exec);
	free_struct(data()->exec);
}

/**
* UTILS:
* print_commands(exec);
* print_prompt(prompt);
* free_prompt(&prompt);
*/
void	init_process(char *line, char **envp, int ac, char **av)
{
	char		**tokens;
	t_args		*args;
	t_redirect	*redirect;
	t_prompt	*prompt;

	tokens = ft_lexer(line);
	args = NULL;
	parser_args(&args, tokens);
	redirect = NULL;
	parser_redirects(&redirect, tokens);
	prompt = NULL;
	parser_prompt(&prompt, args, redirect, tokens);
	free_arr(tokens);
	free_args(&args);
	free_redirects(&redirect);
	exec_process(prompt, envp);
}

static int	handle_any_args(char **cmd_line, char **envp, int ac, char **av)
{
	if (ac == 3 && !ft_strncmp(av[1], "-c", 3))
		*cmd_line = ft_strdup(av[2]);
	else if (ac != 1)
		return (1);
	new_envp(envp);
	return (0);
}

int	cmdline(char *cmd_line, char **envp, int ac, char **av)
{
	if (handle_any_args(&cmd_line, envp, ac, av))
		return (ft_putstr_fd("Error: Wrong arguments\n", 2));
	while (true)
	{
		if (!cmd_line)
			cmd_line = readline("[minishell]$ ");
		if (!cmd_line)
			exit_finald();
		if (!just_spaces(cmd_line))
		{
			free(cmd_line);
			cmd_line = NULL;
		}
		else
		{
			if (cmd_line && *cmd_line)
				add_history(cmd_line);
			if (!sintax_errors(cmd_line) && ft_strlen(cmd_line) > 0)
				init_process(cmd_line, envp, ac, av);
		}
		free(cmd_line);
		cmd_line = NULL;
		unlink_heredoc();
	}
	return (0);
}

int	main(int ac, char *av[], char *envp[])
{
	char	*cmd_line;
	char	cwd[PATH_MAX];

	cmd_line = NULL;
	getcwd(cwd, PATH_MAX);
	data()->cwd = cwd;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sigint);
	cmdline(cmd_line, envp, ac, av);
	return (data()->exit_status);
}
