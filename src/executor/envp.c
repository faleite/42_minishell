/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:08:36 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/16 15:30:30 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**envp_exec(char *envp[])
{
	int		i;
	int		len_e;
	char	**new;

	i = 0;
	while (envp[i])
		i++;
	new = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (envp[i])
	{
		new[i] = ft_strdup(envp[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

char	*add_name(char *str)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	new = ft_calloc(i + 1, sizeof(char));
	new[i] = '\0';
	while (--i >= 0)
		new[i] = str[i];
	return (new);
}

char	*add_value(char *str)
{
	char	*curr;

	curr = str;
	if (!curr)
		return (NULL);
	while (*curr && *curr != '=')
		curr++;
	if (*curr == '\0')
		return (NULL);
	curr++;
	return (curr);
}

t_envp	*insert_end_envp(t_envp **head)
{
	t_envp	*new_node;
	t_envp	*current;

	new_node = ft_calloc(1, sizeof(t_envp));
	if (!new_node)
		exit(1);
	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}
	current = *head;
	while (current && current->next)
		current = current->next;
	if (current)
		current->next = new_node;
	return (new_node);
}

void	fill_envp(t_envp **getev, char **envp)
{
	int		i;
	t_envp	*new_node;

	i = 0;
	while (envp && envp[i])
	{
		new_node = insert_end_envp(getev);
		new_node->name = add_name(envp[i]);
		new_node->value = ft_strdup(add_value(envp[i]));
		i++;
	}
}
