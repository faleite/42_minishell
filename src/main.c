/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/09 22:41:07 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	handle_quotes(char *s1, char *s2)
{
	char	sig;

	sig = 1;
	while (*s1)
	{
		if (sig == 1)
		{
			while (*s1 == ' ')
			{
				*s2++ = '_';
				s1++;
			}
			if (*s1 == '\"' || *s1 == '\'')
				sig = *s1;
			*s2++ = *s1++;
		}
		if (sig == '\"' || sig == '\'')
		{
			if (*s1 == sig)
				sig = 1;
			*s2++ = *s1++;
		}
	}
	*s2 = '\0';
}

/**
 * Criar uma funcao que substitui meu separador
 * echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * echo/2"hello      there"/2how/2are/2'you 'doing?/2$USER/2|wc/2-l/2>outfile
*/
char	*sep_replace(char *s1)
{
	char	*s2;
	int		len;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 2));
	if (!s2)
		return (NULL);
	handle_quotes(s1, s2);
	return (s2);
}

void	cmdline(void)
{
	char	*command_line;
	char	**arr;

	arr = NULL;
	while (1)
	{
		command_line = readline("[~/minishell]$ ");
		if (!command_line)
			break ;
		add_history(command_line);
		arr = ft_split(command_line, ' ');
		print_arr(arr);
		free_arr(arr);
		free(command_line);
	}
}

// int	main(int argc, char *argv[])
int	main(void)
{
	char	s1[] = "echo \"hello  '  there\" how are 'you 'doing? $USER |wc -l >outfile";
	char	*s2;

	s2 = sep_replace(s1);
	printf("%s\n%s\n", s1, s2);
	free(s2);
	//cmdline();
	return (0);
}
