/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/05 20:34:16 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	cmdline(void)
{
	char	*command_line;

	while (1)
	{
		command_line = readline("[~/minishell]$ ");
		if (!command_line)
			break ;		
		add_history(command_line);
		printf("Command line: %s\n", command_line);
		free(command_line);
	}
}

int	main(int argc, char *argv[])
{
	//char *s = "echo hello      there" how are 'you 'doing? $USER |wc -l >outfile";
	cmdline();
	return (0);
}
