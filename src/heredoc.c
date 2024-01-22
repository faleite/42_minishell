/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:14 by feden-pe          #+#    #+#             */
/*   Updated: 2024/01/22 17:39:42 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

int	free_str(void *obj)
{
	free(obj);
	return (1);
}

void	ft_heredoc(t_shell *command, char *delimiter)
{
	char	*str;

	str = NULL;
	close(command->fd[0]);
	close(command->fd[1]);
	if (pipe(command->fd) < 0)
		return ;
	while (!ft_equalstr(str, delimiter) && free_str(str))
	{
		str = readline("> ");
		if (!ft_equalstr(str, delimiter))
		{
			write(command->fd[1], str, ft_strlen(str));
			write(command->fd[1], "\n", 1);
		}
	}
	close(command->fd[1]);
	free_str(str);
}
