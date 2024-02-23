/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:37:24 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/22 18:39:25 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <linux/limits.h>

static char	*get_home(char *path)
{
	char	*tmp;

	path++;
	tmp = ft_strjoin("/home/", get_value("USER"));
	path = ft_strjoin(tmp, path);
	free(tmp);
	return (path);
}

static void	change_directory(char *path, int flag, int outfile)
{
	char	old[PATH_MAX];
	char	new[PATH_MAX];

	getcwd(old, PATH_MAX);
	if (*path == '~')
		path = get_home(path);
	if (chdir(path) == -1)
	{
		ft_putendl_fd("minishell: cd: No such file or directory", 2);
		data()->exit_status = 1;
		return ;
	}
	else
	{
		update_value("OLDPWD", old);
		getcwd(new, PATH_MAX);
		update_value("PWD", new);
	}
	if (flag)
		pwd(outfile);
	data()->exit_status = 0;
}

static void	cd_default(char *name, int flag, int outfile)
{
	char	*path;

	path = get_value(name);
	if (!ft_strcmp(path, "\0"))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd(" not set", 2);
	}
	else if (flag)
		change_directory(path, 1, outfile);
	else
		change_directory(path, 0, outfile);
}

void	cd(t_command *command, int outfile)
{
	if (!command->args[1] || !ft_strcmp("~", command->args[1]))
		cd_default("HOME", 0, outfile);
	else if (command->args[1][0] == '-' && !command->args[1][1])
		cd_default("OLDPWD", 1, outfile);
	else
	{
		if (command->args[1] && command->args[2])
		{
			ft_putendl_fd("minishell: cd: too many arguments", 2);
			data()->exit_status = 1;
			return ;
		}
		else if (command->args[1][0] == '\0')
		{
			data()->exit_status = 0;
			return ;
		}
		else
			change_directory(command->args[1], 0, outfile);
	}
}
