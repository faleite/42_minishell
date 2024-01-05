/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:02:46 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/05 18:43:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	print_redirects(t_redirect *root)
{
	t_redirect	*curr;

	curr = root;
	while (curr)
	{
		printf("redirect\n");
		printf("token_id: %d\n", curr->token_id);
		printf("token_id: %s\n", curr->file);
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
		curr = curr->next;
		i++;
	}
	return (i);
}
