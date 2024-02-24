/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:18:00 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/23 23:21:14 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char	*arg)
{
	if (!arg)
		return (0);
	else if ((ft_strcmp(arg, "echo") == 0))
		return (1);
	else if ((ft_strcmp(arg, "pwd") == 0))
		return (1);
	else if ((ft_strcmp(arg, "cd") == 0))
		return (1);
	else if ((ft_strcmp(arg, "env") == 0))
		return (1);
	else if ((ft_strcmp(arg, "export") == 0))
		return (1);
	else if ((ft_strcmp(arg, "unset") == 0))
		return (1);
	else if ((ft_strcmp(arg, "exit") == 0))
		return (1);
	return (0);
}

void	builtins(t_command *command, int infile, int outfile)
{
	if (command->is_exec == 1 && data()->is_exec_all == 1)
	{
		if ((ft_strcmp(command->args[0], "echo") == 0))
			echo(command, outfile, infile);
		else if ((ft_strcmp(command->args[0], "pwd") == 0))
			pwd(outfile);
		else if (data()->single_cmd == 1 && \
			(ft_strcmp(command->args[0], "cd") == 0))
			cd(command, outfile);
		else if ((ft_strcmp(command->args[0], "env") == 0))
			env(outfile);
		else if (ft_strcmp(command->args[0], "export") == 0)
			ft_export(command->args, outfile);
		else if ((ft_strcmp(command->args[0], "unset") == 0))
			unset(command);
		else if ((ft_strcmp(command->args[0], "exit") == 0))
			exit_builtin(command);
	}
	if (infile != 0)
		close(infile);
	if (outfile != 1)
		close(outfile);
}
