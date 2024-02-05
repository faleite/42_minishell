/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:09:18 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/01 13:28:38 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	parser_prompt(t_prompt **prompt, t_args *arg, \
						t_redirect *red, char **toks)
{
	t_prompt		*new_node;
	t_args			*curr_args;
	t_redirect		*curr_red;

	curr_args = arg;
	curr_red = red;
	while ((curr_args && curr_args) && (curr_args->next && curr_red->next))
	{
		new_node = insert_end_parser(prompt);
		fill_prompt(new_node, curr_args, curr_red, toks);
		curr_args = curr_args->next;
		curr_red = curr_red->next;
	}
	new_node = insert_end_parser(prompt);
	fill_prompt(new_node, curr_args, curr_red, toks);
}

/* node->path = fct_path(); put in line: 46 */
void	fill_prompt(t_prompt *node, t_args *arg, t_redirect *red, char **toks)
{
	int	i;
	int	num_tok;

	i = 0;
	num_tok = (count_tokens(toks));
	node->args = ft_calloc((num_tok + 1), sizeof(char *));
	node->tokens = ft_calloc((num_tok + 1), sizeof(char *));
	node->tokens_id = ft_calloc((num_tok + 1), sizeof(int));
	while (arg && (arg->args && arg->args[i]))
	{
		node->args[i] = ft_strdup(arg->args[i]);
		i++;
	}
	node->args[i] = NULL;
	i = 0;
	while (red && (red->tokens && red->tokens[i]))
	{
		node->tokens_id[i] = red->tokens_id[i];
		node->tokens[i] = ft_strdup(red->tokens[i]);
		i++;
	}
	node->tokens[i] = NULL;
}

t_prompt	*insert_end_parser(t_prompt **root)
{
	t_prompt	*new_node;
	t_prompt	*curr;

	new_node = ft_calloc(1, sizeof(t_prompt));
	if (!new_node)
		exit(1);
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
	return (new_node);
}
