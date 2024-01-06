/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:02:46 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/06 19:59:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	print_args(t_prompt *root)
{
	int			i;
	t_prompt	*curr;

	i = 0;
	curr = root;
	while (curr)
	{
		printf("args\n");
		while (curr->args[i])
			printf("argumentos: %s ,", curr->args[i++]);
		printf("\n");
		curr = curr->next;
	}
}

void	print_redirects(t_redirect *root)
{
	t_redirect	*curr;

	curr = root;
	while (curr)
	{
		printf("redirect\n");
		printf("token_id: %d\n", curr->token_id);
		printf("File or EOF: %s\n", curr->token);
		curr = curr->next;
	}
}

int	cmds_size(t_redirect *root)
{
	t_redirect	*curr;
	size_t		i;

	curr = root;
	i = 0;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
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
		free(aux->token);
		free(aux);
	}
	*root = NULL;
}
