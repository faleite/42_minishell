/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:52:45 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 11:44:33 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	pwd(t_data *data, char **str)
{
	char	buf[PATH_MAX];

	if (!data || !str)
		return (-1);
	if (!getcwd(buf, PATH_MAX))
		perror("pwd:");
	ft_putendl_fd(buf, 1);
	return (0);
}
