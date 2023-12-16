/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:53:27 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/09 22:37:01 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	change_dir(char *str, char **oldpwd, char *pwd)
{
	*oldpwd = ft_strdup(pwd);
	if (chdir(str) == -1)
	{
		free(*oldpwd);
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	getcwd(pwd, PATH_MAX);
	return (0);
}

void	change_pwd_oldpwd(t_pair *temp, char *buf, char *oldpwd)
{
	while (temp->next)
	{
		if (!ft_strncmp(temp->key, "OLDPWD=", 7))
		{
			free(temp->value);
			temp->value = ft_strdup(oldpwd);
			free(oldpwd);
			oldpwd = NULL;
		}
		if (!ft_strncmp(temp->key, "PWD=", 4))
		{
			free(temp->value);
			temp->value = ft_strdup(buf);
		}
		temp = temp->next;
	}
	if (oldpwd)
		free(oldpwd);
}

char	*get_home(t_data *data)
{
	t_pair	*temp;

	temp = data->env;
	while (temp)
	{
		if (!ft_strncmp(temp->key, "HOME=", 6))
			return (temp->value);
		temp = temp->next;
	}
	temp = data->exported_vars;
	while (temp)
	{
		if (!ft_strncmp(temp->key, "HOME=", 6))
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

int	cd(t_data *data, char **str)
{
	char	*oldpwd;
	char	*new_path;
	char	pwd[PATH_MAX];

	new_path = str[0];
	getcwd(pwd, PATH_MAX);
	if (str[0] && str[1])
	{
		data->exit_status = 1;
		return (ft_putendl_fd("minishell: cd: too many arguments", 2));
	}
	if (!new_path)
	{
		new_path = get_home(data);
		if (!new_path)
		{
			data->exit_status = 1;
			return (ft_putendl_fd("minishell: cd: HOME not set", 2));
		}
	}
	oldpwd = NULL;
	data->exit_status = change_dir(new_path, &oldpwd, pwd);
	if (!data->exit_status)
		change_pwd_oldpwd(data->env, pwd, oldpwd);
	return (0);
}
