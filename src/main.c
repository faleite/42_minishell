/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/06 19:48:53 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

#define WD_NUM 1000
#define WD_LEN 1000

char	**sft_split(char *str)
{
	char	**arr;
	char	c;
	int		j;
	int		k;

	arr = (char **)malloc(sizeof(char *) * WD_NUM);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	j = 0;
	c = 32;
	while (*str != '\0')
	{
		if (*str == 34 || *str == 39)
			c = 0;
		if (*str > c)
		{
			k = 0;
			arr[j] = (char *)malloc(sizeof(char) * WD_LEN);
			while (*str > c)
			{
				arr[j][k++] = *str++;
				if (*str == 34 || *str == 39)
					c = 32;
			}
			arr[j][k] = '\0';
			j++;
		}
		else
			str++;
	}
	arr[j] = 0;
	return (arr);
}

char	**cmd_split(char *line)
{
	char	**arr;

	arr = sft_split(line);
	return (arr);
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
		while (*arr)
			printf("%s, ", *arr++);
		printf("\n");
		free(command_line);
	}
}

int	main(int argc, char *argv[])
{
	//char *s = "echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile";
	cmdline();
	return (0);
}
