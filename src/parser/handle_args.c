/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:00:55 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/08 21:18:58 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_prompt	*insert_end(t_prompt **root)
{
	t_prompt	*new_node;
	t_prompt	*curr;

	new_node = calloc(1, sizeof(t_prompt));
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

int	count_tokens(char **tokens)
{
	int	len;

	len = 0;
	while (tokens[len])
		len++;
	return (len);
}

int	fill_args(t_prompt *node, char **tokens, int i)
{
	int	j;
	int	num_tok;

	j = 0;
	num_tok = count_tokens(tokens);
	node->args = calloc((num_tok + 1), sizeof(char *));
	if (node->args == NULL)
		exit(1);
	while ((tokens[i] != NULL && ft_strcmp(tokens[i], "|")))
	{
		node->args[j] = strdup(tokens[i]);
		i++;
		j++;
	}
	node->args[j] = NULL;
	return (i);
}

void	ft_parser(t_prompt **prompt, char **tokens)
{
	int			i;
	t_prompt	*new_node;

	i = 0;
	while (tokens[i])
	{
		new_node = insert_end(prompt);
		while (tokens[i] && ft_strcmp(tokens[i], "|"))
		{
			if ((!ft_strcmp(tokens[i], "<") || !ft_strcmp(tokens[i], ">") || \
				!ft_strcmp(tokens[i], ">>") || !ft_strcmp(tokens[i], "<<")) \
				&& tokens[i + 1])
				i += 2;
			else
			{
				i = fill_args(new_node, tokens, i);
			}
		}
		i++;
	}
}

// int	main(void)
// {
// 	// Cria um novo nó e insere-o no final da lista
// 	t_prompt *root = NULL;

// 	// Define um array de strings
// 	char *strings[] = {"<", "file", "string1", "|", "string3", NULL};

// 	// Preenche o array args do novo nó com as strings
// 	ft_parser(&root, strings);
	
// 	print_prompt(root);

// 	// ... (use a lista conforme necessário)

// 	// Não se esqueça de liberar a memória alocada para a lista e suas strings quando terminar de usá-las
// 	// free_list(root);
// 	return (0);
// }


// t_prompt	*fill_data_args(char **tokens)
// {
// 	int			i;
// 	t_prompt	*args;

// 	// args = ft_calloc(1, sizeof(t_prompt)); // Aloque memória para args
//     // if (!args) // Verifique se a alocação de memória foi bem-sucedida
//     //     exit(1);

//     // args->args = ft_calloc(MAX_TOKENS, sizeof(char *)); // Aloque memória para args->args
//     // if (!args->args) // Verifique se a alocação de memória foi bem-sucedida
//     //     exit(1);

// 	i = 0;
// 	while (tokens[i])
// 	{
// 		while (ft_strcmp(tokens[i], "|"))
// 		{
// 			if ((!ft_strcmp(tokens[i], "<") || !ft_strcmp(tokens[i], ">") || \
// 				!ft_strcmp(tokens[i], ">>") || !ft_strcmp(tokens[i], "<<")) \
// 				&& tokens[i + 1])
// 				i += 2;
// 			else
// 			{
// 				node_insert_args(&args, tokens[i]);
// 				i++;
// 			}
// 		}
// 		i++;
// 	}
// 	return (args);
// }
