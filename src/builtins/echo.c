/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:23:51 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/08 17:20:38 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print(char **map, int outfile)
{
	int	i;

	i = 2;
	if (!map[i])
		return ;
	while (map[i + 1])
	{
		ft_putstr_fd(map[i], outfile);
		ft_putchar_fd(' ', outfile);
		i++;
	}
	ft_putstr_fd(map[i], outfile);
}

void	ft_print_nl(char **map, int outfile)
{
	int	i;

	i = 1;
	if (!map[i])
		return ;
	while (map[i + 1])
	{
		ft_putstr_fd(map[i], outfile);
		ft_putchar_fd(' ', outfile);
		i++;
	}
	ft_putendl_fd(map[i], outfile);
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
	if (is_flag(command))
		ft_print(command->args, outfile);
	else
		ft_print_nl(command->args, outfile);
}
