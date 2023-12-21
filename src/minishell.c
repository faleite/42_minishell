/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/21 22:41:33 by faaraujo         ###   ########.fr       */
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
	//char	*s5;
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
	//s5 = strtrim_quotes(s4);
	arr = ft_split(s4, '\2');
	free(s4);
	//return (s5);
	return (arr);
}

void	cmdline(void)
{
	char	*command_line;
	char	**arr;
	//char	*str;

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
		//str = sep_replace(command_line);
		//printf("%s\n", str);
		//free(str);
		print_arr(arr);
		free_arr(arr);
		free(command_line);
	}
}


int	main(void)
{
	// char	s1[] = "echo \"$HOME '$PWD' >>>\" $USER '$PWD' ~///fal";
	// char	s1[] = "\"$HOME' '$USER' >>>\" '$PWD' $SHELL";
	// char	s1[] = "<<$USER \"$PWD '$USER'u | $'USER' 'hola'\" ~/src '$USER' $HOME|'tr' -d / >outfile";
	// char	s1[] = "$USER '$USER'  4 $ $'USER' $  \"SHELL\" \"$SHELL\"   $    $";
	//char	s1[] = "<<Makefile cat| echo \"$PWD < > | 'hola'\" $USER || 'tr' -d / >outfile";
	//char	**arr;
	// printf("%s\n", s1);
	// sep_replace(s1);

	//arr = sep_replace(s1);
	cmdline();
	// printf("=======\n");
	// printf("Parser:\n");
	// printf("=======\n");
	// print_arr(arr);
	// free_arr(arr);

	// char s1[] = "\"Hello, World!\"";
    // char *result = strtrim_quotes(s1);
    // //char *result = ft_strtrim(s1, "\'");

    // printf("Original: %s\n", s1);
    // printf("Trimmed: %s\n", result);
    // free(result);
	return (0);
}
