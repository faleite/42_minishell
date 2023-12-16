/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 06:47:38 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 13:31:32 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_pair(t_pair *pair)
{
	t_pair	*temp;

	while (pair)
	{
		temp = pair;
		free(pair->key);
		free(pair->value);
		pair = pair->next;
		free(temp);
	}
}

void	free_path(char **path)
{
	int	i;

	i = 0;
	if (!path)
		return ;
	while (path[i] != NULL)
		free(path[i++]);
	free(path);
}

void	free_data(t_data *data)
{
	free(data->pid);
	free(data->pipes.next);
	free_path(data->path);
	free_pair(data->env);
	free_pair(data->exported_vars);
}
