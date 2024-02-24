/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:34:11 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/24 16:11:08 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	change_in(t_command *command, int infile)
{
	if (command->infile_fd != -1)
	{
		if (infile != 0)
			close(infile);
		infile = command->infile_fd;
	}
	return (infile);
}

int	change_out(t_command *command, int outfile)
{
	if (command->outfile_fd != -1)
	{
		outfile = command->outfile_fd;
		if (command->fd[1] > 0)
			close(command->fd[1]);
	}
	else if (command->next)
		outfile = command->fd[1];
	else if (command->fd[1] != -1)
		close(command->fd[1]);
	return (outfile);
}

void	ft_dup2(t_command *command, int infile, int outfile)
{
	if (command->fd[0] != -1)
		close(command->fd[0]);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		exit(0);
	if (outfile != 1)
		close(outfile);
	if (dup2(infile, STDIN_FILENO) < 0)
		exit(0);
	if (infile != 0)
		close(infile);
}
