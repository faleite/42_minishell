/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/08 22:18:47 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s, ", arr[i++]);
	}
	printf("\n");
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i++]);
	}
	free(arr);
}

/**
 * Criar uma funcao que substitui meu separador
 * echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * echo/2"hello      there"/2how/2are/2'you 'doing?/2$USER/2|wc/2-l/2>outfile
*/
char	*sp_replace(char *s1)
{
	char	*s2;
	char	rep;
	int		i;

	i = 0;
	rep = 1;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 2));
	if (!s2)
		return (NULL);
	while (*s1)
	{
		if (rep == 1)
		{
			while (*s1 == ' ')
			{
				s2[i++] = '2';
				s1++;
			}
			if (*s1 == '\"' && rep == 1)
				rep = '\"';
			s2[i++] = *s1++;
		}
		if (rep == '\"')
		{
			if (*s1 == '\"' && rep == '\"')
				rep = 1;
			s2[i++] = *s1++;
		}
	}
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
		arr = sft_split(command_line);
		print_arr(arr);
		free_arr(arr);
		free(command_line);
	}
}

// int	main(int argc, char *argv[])
int	main(void)
{
	char *s = "   echo  \"hello  '    there\" how are 'you 'doing? $USER |wc -l >outfile";

	printf("%s\n%s\n", s, sp_replace(s));
	//cmdline();
	return (0);
}
