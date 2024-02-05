/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:33:49 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/05 03:22:16 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static t_command	*find_tail(t_command *head)
{
	t_command	*current;

	if (!head)
		return (NULL);
	current = head;
	while (current->next)
		current = current->next;
	return (current);
}

void	new_struct(t_prompt *prompt, t_command **head)
{
	t_command	*new;
	t_command	*current;
	int			i;

	i = 0;
	new = ft_calloc(1, sizeof(t_command));
	new->path = cmd_path(prompt->args[0]);
	new->args = prompt->args;
	new->prompt = prompt;
	new->fd[0] = STDIN_FILENO;
	new->fd[1] = STDOUT_FILENO;
	new->infile_fd = -1;
	new->outfile_fd = -1;
	if (!*head)
	{
		*head = new;
		return ;
	}
	current = find_tail(*head);
	current->next = new;
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	print_commands(t_command *head)
{
	t_command	*current;

	current = head;
	while (current)
	{
		print_map(current->args);
		printf("Path: %s\n", current->path);
		printf("Fds: %d, %d\n", current->fd[0], current->fd[1]);
		printf("Infile_fd: %d Outfile_fd: %d\n", current->infile_fd, current->outfile_fd);
		printf("Current: %p\n", current);
		printf("Next: %p\n\n\n", current->next);
		current = current->next;
	}
}


t_command	*init_exec(t_prompt *prompt)
{
	t_command	*head;

	head = NULL;
	while (prompt)
	{
		new_struct(prompt, &head);
		prompt = prompt->next;
	}
	return (head);
}

void	free_struct(t_command *head)
{
	t_command	*current;
	t_command	*tmp;

	current = head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free_map(tmp->args);
		free(tmp->path);
		free_prompt(&tmp->prompt);
		free(tmp);
	}
	head = NULL;
	free(head);
}

// void	print_envp(void)
// {
// 	t_envp	*current;
//
// 	current = getev();
// 	while (current)
// 	{
// 		printf("Name: %s\nValue: %s\n", current->name, current->value);
// 		current = current->next;
// 	}
// }

void	print_envp(void);

// int		main(int ac, char **av, char **ev)
// {
// 	t_prompt	test;
// 	t_prompt	test2;
// 	t_command	*head;
//
// 	// head = ft_calloc(1, sizeof(t_command));
// 	test.args = ft_calloc(3, sizeof(char *));
// 	test.tokens = ft_calloc(3, sizeof(char *));
// 	test.tokens_id = ft_calloc(3, sizeof(t_enum_token));
//
// 	test2.args = ft_calloc(3, sizeof(char *));
// 	test2.tokens = ft_calloc(3, sizeof(char *));
// 	test2.tokens_id = ft_calloc(3, sizeof(t_enum_token));
//
//
// 	test.args[0] = "cat";
// 	test.args[1] = "-e";
// 	test.args[3] = NULL;
// 	test.tokens[0] = "lol.txt";
// 	test.tokens_id[0] = INFILE_ID;
// 	test.next = &test2;
//
// 	test2.args[0] = "wc";
// 	test2.args[1] = "-w";
// 	test2.args[2] = NULL;
// 	test2.next = NULL;
// 	
// 	ft_fillenvp(ev);
// 	ft_envp(getevarr()->envp);
// 	// print_envp();
//
// 	int	i = 0;
// 	head = init_exec(&test);
// 	ft_open_all(head);
// 	
// 	print_commands(head);
//
// 	// free_struct(head);
// }
