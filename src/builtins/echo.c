/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:23:51 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/23 20:05:58 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_just_quotes(char *map)
{
	if (!ft_strcmp(map, "\"\"") || \
		!ft_strcmp(map, "\'\'") || \
		!ft_strcmp(map, "\0"))
		return (1);
	return (0);
}

static void	print_last(char *map, int outfile, int flag)
{
	if (ft_strcmp(map, "\0"))
	{
		if (flag)
			ft_putstr_fd(map, outfile);
		else
			ft_putstr_fd(map, outfile);
	}
	if (!flag)
		ft_putchar_fd('\n', outfile);
	data()->exit_status = 0;
}

void	ft_print(char **map, int outfile, int flag)
{
	int	i;

	i = 1 + flag;
	if (!map[i])
	{
		if (!flag)
			write(outfile, "\n", 1);
		return ;
	}
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
	print_last(map[i], outfile, flag);
}

static int	is_flag(t_command *command, int i, int j, int flag)
{
	if (!command->args[1])
		return (0);
	while (command->args[i][j])
	{
		i++;
		if (command->args[i] && command->args[i][j] == '-')
		{
			j++;
			if (!command->args[i][j])
				return (flag);
			while (command->args[i][j])
			{
				if (command->args[i][j] != 'n')
					return (flag);
				j++;
			}
		}
		else
			return (flag);
		flag++;
		j = 0;
	}
	return (flag);
}

void	echo(t_command *command, int outfile, int infile)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	ft_print(command->args, outfile, is_flag(command, i, j, flag));
}
