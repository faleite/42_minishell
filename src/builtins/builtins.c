/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:18:00 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/05 03:45:11 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	is_builtin(char	*arg)
{
	if ((ft_strncmp(arg, "echo", 5) == 0))
		return (1);
	else if ((ft_strncmp(arg, "pwd", 3) == 0))
		return (1);
	else if ((ft_strncmp(arg, "cd", 2) == 0))
		return (1);
	else if ((ft_strncmp(arg, "env", 3) == 0))
		return (1);
	else if ((ft_strncmp(arg, "export", 6) == 0))
		return (1);
	else if ((ft_strncmp(arg, "unset", 5) == 0))
		return (1);
	else if ((ft_strncmp(arg, "exit", 4) == 0))
		return (1);
	return (0);
}

void	builtins(t_command *command, int infile, int outfile)
{
	if ((ft_strncmp(command->args[0], "echo", 5) == 0))
		echo(command, outfile);
	else if ((ft_strncmp(command->args[0], "pwd", 3) == 0))
		pwd();
	else if ((ft_strncmp(command->args[0], "cd", 2) == 0))
		cd(command);
	else if ((ft_strncmp(command->args[0], "env", 3) == 0))
		env();
	else if ((ft_strncmp(command->args[0], "export", 6) == 0))
		ft_export(command->args);
	else if ((ft_strncmp(command->args[0], "unset", 5) == 0))
		unset(command);
	else if ((ft_strncmp(command->args[0], "exit", 4) == 0))
		exit_builtin(command);
}
