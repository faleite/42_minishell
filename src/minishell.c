/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:21:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/16 21:44:18 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	aux_inside(int *i, char *sig, char **s1, char **s2)
{
	if (**s1 == '\"')
		*sig = 1;
	(*s2)[(*i)++] = *(*s1)++;
}

static int	inside_dbquotes(char **s1, char **s2, int i, char *sig)
{
	char	*start;
	char	*end;
	char	*var;
	char	*value;

	if (**s1 == '$' && *(*s1 + 1) != '\'')
	{
		start = ++(*s1);
		while (**s1 != ' ' && **s1 != '\'' && **s1 != '\"' && **s1)
			(*s1)++;
		end = *s1;
		var = (char *)malloc(sizeof(char) * ((end - start) + 1));
		ft_strlcpy(var, start, ((end - start) + 1));
		value = getenv(var);
		free (var);
		if (value)
		{
			ft_strlcpy(*s2 + i, value, (ft_strlen(*s1) + ft_strlen(var) + 1));
			i += ft_strlen(value);
		}
	}
	else
		aux_inside(&i, sig, s1, s2);
	return (i);
}

char	*expand_var(char *s1)
{
	int		i;
	char	sig;
	char	*s2;

	i = 0;
	sig = 1;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) * 2);
	while (*s1)
	{
		if (sig == '\"')
		{
			i = inside_dbquotes(&s1, &s2, i, &sig);
		}
		else
		{
			if (*s1 == '\"')
				sig = *s1;
			s2[i++] = *s1++;
		}
	}
	s2[i] = '\0';
	return (s2);
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


int	main(void)
{
	// char	s1[] = "echo \"$HOME '$PWD' >>>\" $USER '$PWD' ~///fal";
	// char	s1[] = "\"$HOME' '$USER' >>>\" '$PWD' $SHELL";
	char	s1[] = "\"$PWD '$USER' | $'USER' 'hola'\" ~/src '$USER' $HOME |'tr' -d / >outfile";
				// output: /home/fal '/home/fal' >>> fal $PWD /home/fal///fal
	char	*s2;

	s2 = expand_var(s1);
	if (s2)
		printf("%s\n", s2);
	else
		printf("\n");
	//free(s2);
	// printf("env: %s\n", getenv("USER"));
	// printf("env: %s\n", getenv("HOME"));
	return (0);
}
