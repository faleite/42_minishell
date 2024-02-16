/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:29:28 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/16 15:30:20 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	*data(void)
{
	static t_data	d;

	return (&d);
}

t_envparr	*getevarr(void)
{
	static t_envparr	envp;

	return (&envp);
}
