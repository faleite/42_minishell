/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:03:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/05 22:07:13 by faaraujo         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
lexer problem
<file|< file2:
<
file
|<
file2
*/
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
		if (!ft_strcmp(tokens[i], "<") && tokens[i + 1])
		{
			node_insert_redirects(&redirect, INPUT_ID, tokens[i + 1]);
			i += 2;
		}
		else
			i++;
	}
	return (redirect);
}
