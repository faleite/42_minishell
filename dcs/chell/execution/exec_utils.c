/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:09:01 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/11 19:02:44 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_len(t_pair *temp_env, t_pair *temp_exported)
{
	int	len;

	len = 0;
	while (temp_env)
	{
		temp_env = temp_env->next;
		len++;
	}
	while (temp_exported)
	{
		temp_exported = temp_exported->next;
		len++;
	}
	return (len);
}

char	**get_env_list(t_pair *env, t_pair *exported_vars)
{
	char	**env_list;
	int		len;
	int		i;

	len = get_len(env, exported_vars);
	env_list = ft_calloc(len + 1, sizeof(t_pair));
	env_list[len] = NULL;
	i = 0;
	while (i < len)
	{
		if (!env)
			break ;
		env_list[i] = ft_strjoin(env->key, env->value);
		env = env->next;
		i++;
	}
	while (i < len)
	{
		if (!exported_vars->key)
			break ;
		env_list[i] = ft_strjoin(exported_vars->key, exported_vars->value);
		exported_vars = exported_vars->next;
		i++;
	}
	return (env_list);
}

void	wait_for_execve(t_data *data, int *status)
{
	t_pid	*pid;

	pid = data->pid;
	data->pipes.open = 0;
	while (pid->value != 0)
	{
		waitpid(pid->value, status, 0);
		if (pid->value == data->pid->value && pid->last)
			data->exit_status = WEXITSTATUS(*status);
		pid = pid->next;
		g_signal--;
	}
	free_pid(data);
}

void	create_list(t_arg *arg, char **arg_list)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (arg[++i].token != NULL)
	{
		if (arg[i].type == STR || arg[i].type == EXEC)
			arg_list[j++] = arg[i].token;
	}
}
