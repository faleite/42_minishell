/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:00:55 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/06 20:16:29 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

#define MAX_TOKENS	10

void	node_insert_args(t_prompt **root, char *token)
{
	int			i;
	t_prompt	*new_node;
	t_prompt	*curr;

	i = 0;
	new_node = ft_calloc(1, sizeof(t_prompt));
	if (!new_node)
		exit (1);
	//new_node->cmd = ft_strdup(token);
	new_node->args = ft_calloc(MAX_TOKENS, sizeof(char *));
	while (i < 2)
		new_node->args[i++] = ft_strdup(token);
	new_node->args[i] = NULL;
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

t_prompt	*fill_data_args(char **tokens)
{
	int			i;
	t_prompt	*args;

	// args = ft_calloc(1, sizeof(t_prompt)); // Aloque memória para args
    // if (!args) // Verifique se a alocação de memória foi bem-sucedida
    //     exit(1);

    // args->args = ft_calloc(MAX_TOKENS, sizeof(char *)); // Aloque memória para args->args
    // if (!args->args) // Verifique se a alocação de memória foi bem-sucedida
    //     exit(1);

	i = 0;
	while (tokens[i])
	{
		while (ft_strcmp(tokens[i], "|"))
		{
			if ((!ft_strcmp(tokens[i], "<") || !ft_strcmp(tokens[i], ">") || \
				!ft_strcmp(tokens[i], ">>") || !ft_strcmp(tokens[i], "<<")) \
				&& tokens[i + 1])
				i += 2;
			else
			{
				node_insert_args(&args, tokens[i]);
				i++;
			}
		}
		i++;
	}
	return (args);
}
