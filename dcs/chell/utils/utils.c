/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:56:07 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 13:31:52 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_nodes(t_node *node)
{
	t_node	*temp;

	while (node)
	{
		free(node->content);
		temp = node->next;
		free(node);
		node = temp;
	}
	free(node);
}

void	free_pairs(t_pair *pair)
{
	t_pair	*temp;

	while (pair)
	{
		free(pair->key);
		free(pair->value);
		temp = pair->next;
		free(pair);
		pair = temp;
	}
	free(pair);
}

void	print_pairs(t_pair *pair)
{
	if (!pair->value)
		return ;
	while (pair)
	{
		if (pair->value)
			printf("%s%s\n", pair->key, pair->value);
		else
			printf("%s\n", pair->key);
		pair = pair->next;
	}
}
