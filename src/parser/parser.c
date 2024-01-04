/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:03:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/04 21:14:41 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

//<<Makefile cat| echo "$PWD <$?> | 'hola'" "$HOME"/src | echo $? '$?' |'tr' -d / >outfile

void	node_insert_redirects(t_redirect **root, int id, char *token)
{
	t_redirect	*new_node;
	t_redirect	*curr;

	new_node = ft_calloc(1, sizeof(t_redirect));
	if (!new_node)
		exit (1);
	new_node->token_id = id;
	new_node->file = ft_strdup(token);
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

void	fill_data_redirect(t_redirect *redirect, char **tokens)
{
	int	i;

	i = 0;
	redirect = NULL;
	while (tokens[i] && ft_strncmp(tokens[i], "|", 1))
	{
		if (tokens[i + 1] && !ft_strncmp(tokens[i], "<", ft_strlen(tokens[i])))
		{
			node_insert_redirects(&redirect, INPUT_ID, tokens[i + 1]);
			i += 2;
		}
		else
			i++;
	}
}