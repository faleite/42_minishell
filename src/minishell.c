/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/14 21:45:56 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

#define VAR_LEN 1000

// char	*var_copy(char **s2)
// {
// 	while (**s2 != ' ' && **s2)
// 	{
		
// 	}
// }

char	*expand_var(char *s2)
{
	char	*s3;
	char	var[VAR_LEN];
	char	*var_env;
	int		i;
	int		j;

	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s2) * 2));
	if (!s3)
		return (NULL);
	i = 0;
	while (*s2)
	{
		if (*s2 == '$') //&& *(s2 - 1) != '\'')
		{
			s2++;
			j = 0;
			while (*s2 != ' ' && *s2)
				var[j++] = *s2++;
			var[j] = '\0';
			printf("var: %s\n", var);
			var_env = getenv(var);
			printf("var_env: %s\n", var_env);
			if (var_env != NULL)
			{
				ft_strlcpy(s2, var_env, ft_strlen(var_env));
				i += ft_strlen(var_env);
			}
		}
		else
			s3[i++] = *s2++;
	}
	s3[i] = '\0';
	return (s3);
}

/**
 * Substitui separador
 * echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * echo/2"hello      there"/2how/2are/2'you 'doing?/2$USER/2|wc/2-l/2>outfile
*/
char	**sep_replace(char *s1)
{
	char	*s2;
	char	**arr;

	arr = NULL;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 2));
	if (!s2)
		return (NULL);
	handle_quotes(s1, s2);
	arr = ft_split(s2, '\2');
	free(s2);
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
		arr = ft_split(command_line, ' ');
		print_arr(arr);
		free_arr(arr);
		free(command_line);
	}
}

// int	main(int argc, char *argv[])
	//char	s1[] = "echo \"hello  '  there\" how are 'you 'doing? $USER |wc -l >outfile";
	//char	s1[] = "<<Makefile cat| echo \"$PWD < > | 'hola'\" ~/src | 'tr' -d / >outfile";
	//char	s1[] = "\"$PWD < > \\ | 'hola'\" ~/src ${USER} $HOME |'tr' -d / >outfile";
	//char	s1[] = "echo|cat || teste >>>> >>ts >>>tdb ||t";
int	main(void)
{
	char	s1[] = "echo \"$HOME '$PWD' >>>\" $USER '$PWD' ~///fal";
				// output: /home/fal '/home/fal' >>> fal $PWD /home/fal///fal
	// char	**arr;*
	char	*s2;

	// arr = sep_replace(s1);*
	//s2 = sep_replace(s1);
	s2 = expand_var(s1);
	printf("%s\n", s2);
	free(s2);
	// printf("String Original: %s\n", s1);*
	// printf("\nFirst parser:\n");*
	// print_arr(arr);*
	// free_arr(arr);*
	//cmdline();
	// printf("env: %s\n", getenv("USER"));
	// printf("env: %s\n", getenv("HOME"));
	return (0);
}
