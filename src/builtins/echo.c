/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:23:51 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/09 18:57:20 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print(char **map, int outfile, int flag)
{
	int	i;

	i = 1 + flag;
	if (!map[i])
		return ;
	while (map[i + 1])
	{
		ft_putstr_fd(map[i], outfile);
		ft_putchar_fd(' ', outfile);
		i++;
	}
	if (flag)
		ft_putendl_fd(map[i], outfile);
	else
		ft_putstr_fd(map[i], outfile);
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
