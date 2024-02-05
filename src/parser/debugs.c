/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:02:46 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/01 13:25:12 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	print_prompt(t_prompt *root)
{
	int			i;
	int			j;
	t_prompt	*curr;

	j = 1;
	curr = root;
	while (curr)
	{
		printf("struct: %d\n", j++);
		printf("cmd: %s\nargs: { ", curr->path);
		i = 0;
		while (curr->args && curr->args[i])
			printf("%s, ", curr->args[i++]);
		printf("}\ntokens_id: { ");
		i = 0;
		while (curr->tokens && curr->tokens[i])
			printf("%d, ", curr->tokens_id[i++]);
		printf("}\n");
		printf("tokens: { ");
		i = 0;
		while (curr->tokens && curr->tokens[i])
			printf("%s, ", curr->tokens[i++]);
		printf("}\n\n");
		curr = curr->next;
	}
}

void	print_args(t_args *root)
{
	int			i;
	int			j;
	t_args		*curr;

	j = 1;
	curr = root;
	while (curr)
	{
		printf("struct: %d\n", j++);
		if (curr->path)
			printf("cmd: %s\n", curr->path);
		printf("args: { ");
		i = 0;
		while (curr->args && curr->args[i])
		{
			printf("%s, ", curr->args[i]);
			i++;
		}
		printf("}\n\n");
		curr = curr->next;
	}
}

void	print_redirects(t_redirect *root)
{
	int			i;
	int			j;
	t_redirect	*curr;

	j = 1;
	curr = root;
	while (curr)
	{
		printf("struct: %d\n", j++);
		printf("tokens_id: { ");
		i = 0;
		while (curr->tokens[i])
			printf("%d, ", curr->tokens_id[i++]);
		printf("}\n");
		printf("tokens: { ");
		i = 0;
		while (curr->tokens[i])
			printf("%s, ", curr->tokens[i++]);
		printf("}\n\n");
		curr = curr->next;
	}
}

void	print_tokens(t_token *root)
{
	t_token		*curr;

	curr = root;
	while (curr)
	{
		printf("%s\n", curr->token);
		curr = curr->next;
	}
}
