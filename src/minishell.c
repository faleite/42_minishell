/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/27 17:40:20 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/**
 * Substitui separador
 * echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * echo/2"hello      there"/2how/2are/2'you 'doing?/2$USER/2|wc/2-l/2>outfile
*/
char	**sep_replace(char *s1)
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

void	cmdline(void)
{
	char	*command_line;
	char	**arr;

	arr = NULL;
	while (1)
	{
		command_line = readline("[minishell]$ ");
		if (!command_line)
		{
			printf("exit\n");
			break ;
		}
		add_history(command_line);
		arr = sep_replace(command_line);
		print_arr(arr);
		free_arr(arr);
		free(command_line);
	}
}

int	main(void)
{
	cmdline();
	return (0);
}
