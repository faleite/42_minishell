/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:05:45 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/11 19:02:13 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_cmd(char **arg_list, t_command_list *cmd_lst)
{
	if (!access("heredoc_163465", O_RDONLY))
		unlink("heredoc_163465");
	if (arg_list)
		free(arg_list);
	free_args(cmd_lst->arg);
	free(cmd_lst->exec_path);
}

int	check_fds(t_data *data, t_command_list *cmd_lst, t_pipe *pipes, int i)
{
	if ((cmd_lst->next || pipes->next->open))
		do_pipes(cmd_lst, pipes);
	while (cmd_lst->arg[i].token != NULL)
	{
		if (cmd_lst->arg[i].type == IN)
			if (open_file(&cmd_lst->in_fd, cmd_lst->arg[i].token,
					O_RDONLY | O_CLOEXEC, 0))
				return (print_file_error("minishell: ", cmd_lst->arg[i].token));
		if (cmd_lst->arg[i].type == OUT)
			if (open_file(&cmd_lst->out_fd, cmd_lst->arg[i].token,
					O_CREAT | O_WRONLY | O_TRUNC | O_CLOEXEC, 0664))
				return (print_file_error("minishell: ", cmd_lst->arg[i].token));
		if (cmd_lst->arg[i].type == APPEND)
			if (open_file(&cmd_lst->out_fd, cmd_lst->arg[i].token,
					O_CREAT | O_WRONLY | O_APPEND | O_CLOEXEC, 0664))
				return (print_file_error("minishell: ", cmd_lst->arg[i].token));
		if (cmd_lst->arg[i].type == HEREDOC)
		{
			if (mini_heredoc(data, cmd_lst->arg[i].token, cmd_lst))
				return (print_file_error("minishell: ", "heredoc"));
			cmd_lst->in_fd = open("heredoc_163465", O_RDONLY | O_CLOEXEC);
		}
		i++;
	}
	return (assign_fds(cmd_lst->in_fd, cmd_lst->out_fd));
}

void	child_error(t_data *data, t_command_list *cmd_lst, char **args)
{
	if (data->pipes.open)
		close(data->pipes.fd[0]);
	revert_fds(cmd_lst);
	ft_putstr_fd(*args, 2);
	ft_putendl_fd(": command not found", 2);
	exit(127);
}

int	execute_execve(t_data *data, t_command_list *cmd_lst, char **args, int pid)
{
	char	**env_list;

	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("minishell: error forking\n", 2);
		return (-1);
	}
	if (pid != 0)
	{
		g_signal++;
		add_pid(data, pid, cmd_lst);
	}
	if (pid == 0)
	{
		g_signal = 0;
		signal(SIGINT, SIG_DFL);
		env_list = get_env_list(data->env, data->exported_vars);
		if (execve(cmd_lst->exec_path, args, env_list) == -1)
			child_error(data, cmd_lst, args);
	}
	return (0);
}

int	check_cmd(t_data *data, t_command_list *cmd_lst, t_pipe *pipes)
{
	char	**arg_list;
	int		status;

	data->pipes.open = 0;
	data->pipes.next->open = 0;
	while (cmd_lst)
	{
		init_cmd_lst(cmd_lst);
		arg_list = get_arg_list(cmd_lst->arg, 0, -1, 0);
		check_path(data, cmd_lst, arg_list, -1);
		if (check_fds(data, cmd_lst, pipes, 0) != 0)
		{
			if (pipes->open)
				close(pipes->fd[1]);
			data->exit_status = 1;
		}
		else if (arg_list && g_signal != -10 && !is_builtin(data, arg_list))
			execute_execve(data, cmd_lst, arg_list, 0);
		revert_fds(cmd_lst);
		free_cmd(arg_list, cmd_lst);
		pipes = pipes->next;
		cmd_lst = cmd_lst->next;
	}
	wait_for_execve(data, &status);
	return (data->exit_status);
}
