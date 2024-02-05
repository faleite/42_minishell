/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:25:47 by anda-cun          #+#    #+#             */
/*   Updated: 2023/09/30 20:14:32 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_pair	*get_env(char **envp)
{
	int		i;
	t_pair	*node;
	t_pair	*temp_node;

	i = 0;
	node = malloc(sizeof(t_pair));
	temp_node = node;
	while (envp[i])
	{
		temp_node->key = ft_substr(envp[i], 0, len_to_char(envp[i], '=') + 1);
		temp_node->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		if (envp[i + 1])
		{
			temp_node->next = malloc(sizeof(t_pair));
			temp_node = temp_node->next;
		}
		else
		{
			temp_node->next = NULL;
			break ;
		}
		i++;
	}
	return (node);
}
