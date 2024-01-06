/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:03:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/06 19:01:22 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	node_insert_redirects(t_redirect **root, int id, char *token)
{
	t_redirect	*new_node;
	t_redirect	*curr;

	new_node = ft_calloc(1, sizeof(t_redirect));
	if (!new_node)
		exit (1);
	new_node->token_id = id;
	new_node->token = ft_strdup(token);
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

static int	insert_redirects(t_redirect **root, int id, char *token)
{
	node_insert_redirects(root, id, token);
	return (2);
}

t_redirect	*fill_data_redirect(char **tokens)
{
	int			i;
	t_redirect	*redirect;

	redirect = NULL;
	i = 0;
	while (tokens[i])
	{
		if (!ft_strcmp(tokens[i], "|"))
			i++;
		else if (!ft_strcmp(tokens[i], "<") && tokens[i + 1])
			i += (insert_redirects(&redirect, INPUT_ID, tokens[i + 1]));
		else if (!ft_strcmp(tokens[i], ">") && tokens[i + 1])
			i += (insert_redirects(&redirect, OUTPUT_ID, tokens[i + 1]));
		else if (!ft_strcmp(tokens[i], ">>") && tokens[i + 1])
			i += (insert_redirects(&redirect, APPEND_ID, tokens[i + 1]));
		else if (!ft_strcmp(tokens[i], "<<") && tokens[i + 1])
			i += (insert_redirects(&redirect, HEREDOC_ID, tokens[i + 1]));
		else
			i++;
	}
	return (redirect);
}
