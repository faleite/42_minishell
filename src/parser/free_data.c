/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:27:45 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/25 15:51:11 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	free_prompt(t_prompt **root)
{
	t_prompt	*curr;
	t_prompt	*aux;

	curr = *root;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		free_arr(aux->args);
		free_arr(aux->tokens);
		free(aux->path);
		free(aux->tokens_id);
		free(aux);
	}
	*root = NULL;
}

void	free_args(t_args **root)
{
	t_args	*curr;
	t_args	*aux;

	curr = *root;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		free_arr(aux->args);
		free(aux->path);
		free(aux);
	}
	*root = NULL;
}

void	free_redirects(t_redirect **root)
{
	t_redirect	*curr;
	t_redirect	*aux;

	curr = *root;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		free_arr(aux->tokens);
		free(aux->tokens_id);
		free(aux);
	}
	*root = NULL;
}

void	free_tokens(t_token **root)
{
	t_token	*curr;
	t_token	*aux;

	curr = *root;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		free(aux->token);
		free(aux);
	}
	*root = NULL;
}