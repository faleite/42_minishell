/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:33:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/08 17:13:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redirect	*insert_end_redirects(t_redirect **root)
{
	t_redirect	*new_node;
	t_redirect	*curr;

	new_node = ft_calloc(1, sizeof(t_redirect));
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

t_args	*insert_end_args(t_args **root)
{
	t_args	*new_node;
	t_args	*curr;

	new_node = ft_calloc(1, sizeof(t_args));
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
