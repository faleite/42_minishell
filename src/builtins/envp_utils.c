/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:46:00 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/24 16:44:55 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_value(char *name, char *value)
{
	t_envp		*current;

	current = data()->envp;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
		{
			free(current->value);
			if (current->value && value)
				current->value = ft_strdup(value);
			else
				current->value = NULL;
			// getevarr()->envp = update_env(getevarr()->envp);
			return ;
		}
		current = current->next;
	}
	current = insert_end_envp(&data()->envp);
	current->name = ft_strdup(name);
	current->value = ft_strdup(value);
	// getevarr()->envp = update_env(getevarr()->envp);
}

char	*get_value(char *name)
{
	static char	str[20];
	char		*status;
	t_envp		*current;
	size_t		i;

	current = data()->envp;
	if (ft_strcmp("?", name) == 0)
	{
		status = ft_itoa(data()->exit_status);
		i = -1;
		while (status[++i])
			str[i] = status[i];
		str[i] = '\0';
		free(status);
		return (str);
	}
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (current->value);
		current = current->next;
	}
	return ("\0");
}

int	node_exists(char *name)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

int	index_heredoc(t_command *current)
{
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (current->prompt->tokens_id[i++])
	{
		if (current->prompt->tokens_id[i] == HEREDOC_ID)
			ret = i;
	}
	return (ret);
}

t_envp	*get_node(char *name)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
