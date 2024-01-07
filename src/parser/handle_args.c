/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:00:55 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/07 17:18:50 by faaraujo         ###   ########.fr       */
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

void	fill_args(t_prompt *node, char **strings, int num_strings)
{
	int	i;

	i = 0;
	node->args = calloc((num_strings + 1), sizeof(char *));
	if (node->args == NULL)
		exit(1);
	while (i < num_strings)
	{
		node->args[i] = strdup(strings[i]);
		i++;
	}
	node->args[num_strings] = NULL;
}

void	print_prompt(t_prompt *root)
{
	int			i;
	t_prompt	*curr;

	i = 0;
	curr = root;
	while (curr)
	{
		printf("prompt ->\n");
		printf("cmd: %s\n", curr->cmd);
		printf("args: { ");
		while (curr->args[i])
			printf("%s ", curr->args[i++]);
		printf("}\n");
		//printf("token_id: %d\n", curr->redirect->token_id);
		//printf("token_id: %s\n", curr->redirect->token);
		curr = curr->next;
	}
}

int	main(void)
{
	// Cria um novo nó e insere-o no final da lista
	t_prompt *root = NULL;
	t_prompt *new_node = insert_end(&root);

	// Define um array de strings
	char *strings[] = {"<", "file", "string1", "string2", "string3"};
	int num_strings = sizeof(strings) / sizeof(strings[0]);

	// Preenche o array args do novo nó com as strings
	fill_args(new_node, strings, num_strings);
	new_node->redirect = fill_data_redirect(strings);
	print_prompt(root);

	// ... (use a lista conforme necessário)

	// Não se esqueça de liberar a memória alocada para a lista e suas strings quando terminar de usá-las
	// free_list(root);
	return (0);
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
