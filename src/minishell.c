/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/04 21:17:01 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/**
 * Substitui separador
 * echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * echo/2"hello      there"/2how/2are/2'you 'doing?/2$USER/2|wc/2-l/2>outfile
*/
char	**ft_lexer(char *s1)
{
	char	*s2;
	char	*s3;
	char	*s4;
	char	**arr;

	arr = NULL;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 2 + 1));
	if (!s2)
		return (NULL);
	handle_quotes(s1, s2);
	replace_spaces(s2);
	s3 = expander_outside(s2);
	free(s2);
	s4 = expander_inside(s3);
	free(s3);
	arr = ft_split(s4, '\2');
	arr = strtrim_quotes(arr);
	free(s4);
	return (arr);
}

int	cmds_size(t_redirect *lst)
{
	t_redirect	*current;
	size_t		i;

	current = lst;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	init_process(char *line)
{
	char		**tokens;
	t_redirect	*redirect;
	
	redirect = ft_calloc(1, sizeof(t_redirect));
	tokens = ft_lexer(line);
	fill_data_redirect(redirect, tokens);
	printf("%d\n", cmds_size(redirect));
	//print_arr(tokens);
	free_arr(tokens);
}

void	cmdline(char *cmd_line)
{
	
	while (1)
	{
		if (!cmd_line)
			cmd_line = readline("[minishell]$ ");
		if (!cmd_line)
		{
			printf("exit\n");
			break ;
		}
		else
		{
			if (*cmd_line)
				add_history(cmd_line);
			init_process(cmd_line);
		}
		free(cmd_line);
		cmd_line = NULL;
		g_status = 0;
	}
}

int	main(void)
{
	char	*cmd_line;
	
	cmd_line = NULL;
	cmdline(cmd_line);
	return (0);
}
