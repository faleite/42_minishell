/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:03:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/03 20:51:22 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	insert_end(t_shell **root, char **tokens, char *token)
{
	t_shell	*new_node;
	t_shell	*curr;

	new_node = malloc(sizeof(t_shell));
	if (!new_node)
		exit(1);
	new_node->next = NULL;
	new_node->full_cmd;
	new_node->full_path;
	new_node->infile;
	new_node->outfile;
	if (!*root)
	{
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}
