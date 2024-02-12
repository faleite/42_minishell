/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:43:16 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/12 19:57:15 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(int outfile)
{
	char	pwd[PATH_MAX];

	if (!getcwd(pwd, PATH_MAX))
		return ;
	ft_putendl_fd(pwd, outfile);
	data()->exit_status = 0;
}
