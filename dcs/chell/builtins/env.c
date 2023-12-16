/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:32:07 by anda-cun          #+#    #+#             */
/*   Updated: 2023/09/30 20:26:27 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/**
 * @brief	print env variables + exported variables with '=' sign, unordered
 */

int	env(t_data *data, char **str)
{
	t_pair	*temp;

	temp = data->env;
	if (*str)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(*str, 2);
		ft_putendl_fd(": too many arguments", 2);
		return (-1);
	}
	print_pairs(temp);
	temp = data->exported_vars;
	if (!temp)
		return (0);
	while (temp)
	{
		if (temp->value)
		{
			ft_putstr_fd(temp->key, 1);
			ft_putendl_fd(temp->value, 1);
		}
		temp = temp->next;
	}
	data->exit_status = 0;
	return (0);
}
