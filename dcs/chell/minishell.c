/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:47:26 by anda-cun          #+#    #+#             */
/*   Updated: 2024/01/24 13:39:49 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_signal;

int	init(t_data *data, char **envp)
{
	data->env = NULL;
	data->env = get_env(envp);
	data->exported_vars = malloc(sizeof(t_pair));
	if (!data->exported_vars)
		return (1);
	data->exported_vars->key = NULL;
	data->exported_vars->value = NULL;
	data->exported_vars->next = NULL;
	data->pipes.open = 0;
	data->pipes.next = malloc(sizeof(t_pipe));
	if (!data->pipes.next)
		return (1);
	data->pipes.next->next = &data->pipes;
	data->path = NULL;
	data->pid = malloc(sizeof(t_pid));
	if (!data->pid)
		return (1);
	data->pid->value = 0;
	data->pid->next = NULL;
	data->exit_status = 0;
	data->exit = 0;
	getcwd(data->cwd, PATH_MAX);
	return (0);
}

void	init_cmd_lst(t_command_list *cmd_lst)
{
	cmd_lst->exec_path = NULL;
	cmd_lst->in_fd = -1;
	cmd_lst->out_fd = -1;
	cmd_lst->stdin = dup(STDIN_FILENO);
	cmd_lst->stdout = dup(STDOUT_FILENO);
}

void	run(t_data *data, char *line)
{
	char			**splitter;
	char			*changes;
	t_command_list	*cmd_lst;

	changes = treat_str(line, 0, 0);
	splitter = ft_split(changes, 2);
	cmd_lst = malloc(sizeof(t_command_list));
	cmd_lst->arg = malloc(sizeof(t_arg) * (ft_strleni(splitter, 0) \
			+ 1));
	parsing(cmd_lst, splitter, 0, 0);
	expand_struct(data, cmd_lst);
	check_cmd(data, cmd_lst, &data->pipes);
	free_all(cmd_lst, changes, splitter);
}

void	minishell(t_data *data, char *line)
{
	while (data->exit == 0)
	{
		if (!line)
			line = readline("minishell$ ");
		if (!line)
			exit_builtin(data, NULL);
		else
		{
			if (line && *line)
				add_history(line);
			if (!check_parse_errors(data, line, 0) && ft_strlen(line) > 0)
				run(data, line);
		}
		free(line);
		line = NULL;
		g_signal = 0;
	}
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_data	data;
	int		exit_status;

	line = NULL;
	g_signal = 0;
	if (ac == 3 && !ft_strncmp(av[1], "-c", 3))
		line = ft_strdup(av[2]);
	else if (ac != 1)
		return (ft_putstr_fd("Error: Wrong arguments\n", 1));
	if (init(&data, envp))
	{
		free_data(&data);
		return (ft_putendl_fd("Error initializing data. Exiting", 2));
	}
	signal(SIGQUIT, SIG_IGN);	
	signal(SIGINT, sigint_handler);
	minishell(&data, line);
	exit_status = data.exit_status;
	free_data(&data);
	return (exit_status);
}
