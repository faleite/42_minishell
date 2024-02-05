/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:37:24 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/05 03:19:01 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	change_directory(char *path, int flag)
{
	char	*old;
	char	*new;
	
	old = getcwd(NULL, 0);
	if (chdir(path) == -1)
		return ;
	else
	{
		update_value("OLDPWD", old);
		new = getcwd(NULL, 0);
		update_value("PWD", new);
		free(new);
	}
	free(old);
	if (flag)
		pwd();
}

static void	cd_default(char *name, int flag)
{
	char	*path;
	
	path = get_value(name);
	if (!path)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" not set", 2);
	}
	else if (flag)
		change_directory(path, 1);
	else
		change_directory(path, 0);
	free(path);
}

void	cd(t_command *command)
{
	if (!command->args[1])
		cd_default("HOME", 0);
	else if (command->args[1][0] == '-' && !command->args[1][1])
		cd_default("OLDPWD", 1);
	else
	{
		if (command->args[2])
		{
			ft_putstr_fd("minishell: cd: Too many arguments", 2);
			return ;
		}
		else
			change_directory(command->args[1], 0);
	}
}