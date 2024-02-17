/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:34:11 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/17 13:29:27 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

int	change_in(t_command *command, int infile)
{
	if (command->infile_fd != -1)
		infile = command->infile_fd;
	return (infile);
}

int	change_out(t_command *command, int outfile)
{
	outfile = command->fd[1];
	if (command->outfile_fd != -1)
	{
		outfile = command->outfile_fd;
		if (command->fd[1] != 1)
			close(command->fd[1]);
	}
	return (outfile);
}

void	ft_dup2(int infile, int outfile)
{
	if (dup2(outfile, STDOUT_FILENO) < 0)
		exit(0);
	if (outfile != 1)
		close(outfile);
	if (dup2(infile, STDIN_FILENO) < 0)
		exit(0);
	if (infile != 0)
		close(infile);
}
