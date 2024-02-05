/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:04:18 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/11 19:02:10 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_arg_list(t_arg *arg, int flag, int i, int len)
{
	char	**arg_list;

	while (arg[++i].token != NULL)
	{
		if (arg[i].type == EXEC)
		{
			if (i == 0 && access(arg[i].token, X_OK | F_OK) != 0)
			{
				print_file_error("minishell: ", arg[i].token);
				arg[i].type = -20;
				flag = 1;
			}
		}
		if (arg[i].type == STR || arg[i].type == EXEC)
			len++;
		if (flag)
			arg[i].type = -20;
	}
	if (len)
		arg_list = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!len || !arg_list)
		return (NULL);
	create_list(arg, arg_list);
	return (arg_list);
}

void	free_pid(t_data *data)
{
	t_pid	*temp;

	while (data->pid->value != 0)
	{
		temp = data->pid;
		data->pid = data->pid->next;
		free(temp);
	}
	data->pid->value = 0;
}

void	add_pid(t_data *data, int pid, t_command_list *cmd_lst)
{
	t_pid	*temp;

	temp = malloc(sizeof(t_pid));
	temp->value = pid;
	if (!cmd_lst->next)
		temp->last = 1;
	else
		temp->last = 0;
	temp->next = data->pid;
	data->pid = temp;
}

char	**get_path(t_data *data)
{
	t_pair	*temp;

	if (data->path)
	{
		free_path(data->path);
		data->path = NULL;
	}
	temp = data->env;
	while (temp)
	{
		if (!ft_strncmp(temp->key, "PATH=", 5))
			return (ft_split(temp->value, ':'));
		temp = temp->next;
	}
	temp = data->exported_vars;
	while (temp)
	{
		if (temp && temp->key && !ft_strncmp(temp->key, "PATH=", 5))
			return (ft_split(temp->value, ':'));
		temp = temp->next;
	}
	return (NULL);
}

int	check_path(t_data *data, t_command_list *cmd_lst, char **str, int i)
{
	char	*temp;
	char	*path_to_test;

	path_to_test = NULL;
	data->path = get_path(data);
	if (!data->path || !*data->path || !str)
		path_to_test = ft_strdup("");
	else if (!ft_strncmp("./", *str, 2) || !ft_strncmp("/", *str, 1))
		path_to_test = ft_strdup(*str);
	cmd_lst->exec_path = path_to_test;
	if (!path_to_test)
	{
		while (data->path[++i])
		{
			temp = ft_strjoin(data->path[i], "/");
			path_to_test = ft_strjoin(temp, *str);
			free(temp);
			if (access(path_to_test, X_OK | F_OK) == 0)
				break ;
			else if (data->path[i + 1])
				free(path_to_test);
		}
	}
	cmd_lst->exec_path = path_to_test;
	return (0);
}
