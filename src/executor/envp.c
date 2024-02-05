/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:08:36 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/05 19:57:02 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

// static t_envp	*find_tail(t_envp **head)
// {
// 	t_envp	*current;
//
// 	current = *head;
// 	while (current->next)
// 		current = current->next;
// 	return (current);
// }


// t_envp	*getev(void)
// {
// 	static t_envp envp;
//
// 	return (&envp);
// }

t_envparr *getevarr(void)
{
	static t_envparr envp;

	return (&envp);
}

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
	while (i--)
		new[i] = str[i];
	return (new);
}

char	*add_value(char *str)
{
	if (!str)
		return (NULL);
	while (*str && *str != '=')
		str++;
	str++;
	return (str);
}

// static void	add_tail(t_envp *head, char *envp)
// {
// 	t_envp	*new;
// 	t_envp	*current;
//
// 	new = malloc(sizeof(t_envp));
// 	if (add_name(envp) && add_value(envp))
// 	{
// 		new->name = add_name(envp);
// 		new->value = add_value(envp);
// 	}
// 	if (!head)
// 	{
// 		new->next = NULL;
// 		head = new;
// 		return ;
// 	}
// 	current = find_tail(&head);
// 	current->next = new;
// }

// void	ft_envp(char *envp[])
// {
// 	int		i;
// 	t_envp	*head;
//
// 	i = 0;
// 	head = NULL;
// 	while (envp[i])
// 	{
// 		add_tail(getev(), envp[i]);
// 		i++;
// 	}
// }

void	print_envp(t_envp *head)
{
	t_envp	*current;

	current = head;
	while (current)
	{
		printf("Name: %s\nValue: %s\n", current->name, current->value);
		current = current->next;
	}
}

void	ft_fillenvp(char *envp[])
{
	getevarr()->envp = envp_exec(envp);
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

t_data *data(void)
{
	static t_data d;

	return (&d);
}


// int	main(int ac, char **av, char **ev)
// {
// 	ft_envp(ev);
// 	export("a=f3k");
// 	print_envp();
// 	return (0);
// }
