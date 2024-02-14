/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:23:51 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/14 16:37:20 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_just_quotes(char *map)
{
	if (!ft_strncmp(map, "\"\"", 2) || \
		!ft_strncmp(map, "\'\'", 2))
		return (1);
	return (0);
}

void	ft_print(char **map, int outfile, int flag)
{
	int	i;

	i = 1 + flag;
	if (!map[i])
		return ;
	while (map[i + 1])
	{
		if (is_just_quotes(map[i]))
			i++;
		else
		{
			ft_putstr_fd(map[i], outfile);
			ft_putchar_fd(' ', outfile);
			i++;
		}
	}
	if (is_just_quotes(map[i]))
	 	ft_putchar_fd('\2', outfile);
	else if (flag)
		ft_putstr_fd(map[i], outfile);
	else
		ft_putstr_fd(map[i], outfile);
	if (!flag)
	 	ft_putchar_fd('\n', outfile);
	data()->exit_status = 0;
}

static int	is_flag(t_command *command)
{
	int	i;

	i = 0;
	if (!command->args[1] || !command->args[1][0])
		return (0);
	if (command->args[1][0] != '-' || !command->args[1][1])
		return (0);
	while (command->args[1][++i])
	{
		if (command->args[1][i] != 'n')
			return (0);
	}
	return (1);
}

void	echo(t_command *command, int outfile)
{
	ft_print(command->args, outfile, is_flag(command));
}
