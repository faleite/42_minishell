/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/04 21:17:52 by faaraujo         ###   ########.fr       */
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
	// char *s = "echo export cd \'$USER\' $ my name is grep>><<><>0  Makefile  \"|\'$USER grep\' $USER$USER $$\"| \'grep x@ $PATH\' >| file $USE | $USER$user$1eugen$USER$1USER--$-";
	cmdline();
	return (0);
}
