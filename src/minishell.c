/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/18 22:05:49 by faaraujo         ###   ########.fr       */
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
	s2 = expander_inside(s1);
	s3 = expander_outside(s2);
	s4 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 2));
	if (!s4)
		return (NULL);
	handle_quotes(s3, s4);
	arr = ft_split(s4, '\2');
	free(s2);
	free(s3);
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
	// char	s1[] = "echo \"$HOME '$PWD' >>>\" $USER '$PWD' ~///fal";
	// char	s1[] = "\"$HOME' '$USER' >>>\" '$PWD' $SHELL";
	//char	s1[] = " $USER \"$PWD '$USER'u | $'USER' 'hola'\" ~/src '$USER' $HOME |'tr' -d / >outfile";
	//char	s1[] = "$USER '$USER'  4 $ $'USER' $  \"SHELL\" \"$SHELL\"   $    $";
	char	s1[] = "<<Makefile cat| echo \"$PWD < > | 'hola'\" $USER || 'tr' -d / >outfile";
	char	**arr;

	//cmdline();
	arr = sep_replace(s1);
	printf("Comamnd line: %s\n", s1);
	printf("=======\n");
	printf("Parser:\n");
	printf("=======\n");
	print_arr(arr);
	free_arr(arr);
	return (0);
}
