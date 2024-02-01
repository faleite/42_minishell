/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:08:36 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/01 15:36:01 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

static t_envp	*find_tail(t_envp **head)
{
	t_envp	*current;

	current = *head;
	while (current->next)
		current = current->next;
	return (current);
}


t_envp	*getev(void)
{
	static t_envp envp;

	return (&envp);
}

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
	while (*str && *str != '=')
		str++;
	str++;
	return (str);
}

static void	add_tail(t_envp *head,char *envp)
{
	t_envp	*new;
	t_envp	*current;

	new = malloc(sizeof(t_envp));
	new->name = add_name(envp);
	new->value = add_value(envp);
	if (!head)
	{
		new->next = NULL;
		head = new;
		return ;
	}
	current = find_tail(&head);
	current->next = new;
}

void	ft_envp(char *envp[])
{
	int		i;

	i = 0;
	while (envp[i])
	{
		add_tail(getev(), envp[i]);
		i++;
	}
}

void	print_envp(void)
{
	t_envp	*current;

	current = getev();
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

void	export(char *new_value)
{
		add_tail(getev(), new_value);
}


// int	main(int ac, char **av, char **ev)
// {
// 	ft_envp(ev);
// 	export("a=f3k");
// 	print_envp();
// 	return (0);
// }
