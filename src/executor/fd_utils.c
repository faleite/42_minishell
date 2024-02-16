/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:55:36 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/16 15:58:43 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	error_msg(char *delimiter)
{
	ft_putstr_fd("minishell: warning: here-document ", STDERR_FILENO);
	ft_putstr_fd("delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(delimiter, STDERR_FILENO);
	ft_putendl_fd("')", STDERR_FILENO);
}

int	check_readline(char *str, char *delimiter)
{
	if (!str || \
			ft_strncmp(str, delimiter, ft_strlen(delimiter) + 1) == 0)
	{
		if (!str)
			error_msg(delimiter);
		free(str);
		clean_newline();
		close(data()->h_fd);
		return (1);
	}
	return (0);
}
