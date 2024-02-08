/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:00:07 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/08 17:18:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_pipe(char *s1, char *s2)
{
	char	sig;

	sig = 1;
	while (s1 && *s1)
	{
		if (sig == 1)
		{
			if (*s1 != '\0' && *s1 == '|')
			{
				*s2++ = ' ';
				while (*s1 != '\0' && *s1 == '|')
					*s2++ = *s1++;
				if (*s1 != '\0')
					*s2++ = ' ';
			}
			if (s1 && (*s1 == '\"' || *s1 == '\''))
				sig = *s1;
			if (s1 && s2 && *s1)
				*s2++ = *s1++;
		}
		else
			end_quote(&sig, &s1, &s2);
	}
	if (s2)
		*s2 = '\0';
}

void	handle_redirects(char *s1, char *s2)
{
	char	sig;

	sig = 1;
	while (s1 && *s1)
	{
		if (sig == 1)
		{
			if (*s1 != '\0' && (*s1 == '<' || *s1 == '>'))
			{
				*s2++ = ' ';
				while (*s1 != '\0' && (*s1 == '<' || *s1 == '>'))
					*s2++ = *s1++;
				if (*s1 != '\0')
					*s2++ = ' ';
			}
			if (s1 && (*s1 == '\"' || *s1 == '\''))
				sig = *s1;
			if (s1 && s2 && *s1)
				*s2++ = *s1++;
		}
		else
			end_quote(&sig, &s1, &s2);
	}
	if (s2)
		*s2 = '\0';
}

/**
 * Substitui separador
 * echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * echo/2"hello      there"/2how/2are/2'you 'doing?/2$USER/2|wc/2-l/2>outfile
*/
void	replace_spaces(char *s1)
{
	char	sig;
	int		i;

	sig = 1;
	i = 0;
	while (s1 && s1[i])
	{
		if (sig == 1)
		{
			while (s1 && s1[i] == ' ' && s1[i + 1] != '\0')
				s1[i++] = '\2';
			if (s1 && s1[i] && (s1[i] == '\"' || s1[i] == '\''))
				sig = s1[i];
		}
		else
		{
			if (sig == '\"' || sig == '\'')
			{
				if (s1 && s1[i] == sig)
					sig = 1;
			}
		}
		i++;
	}
	s1[i] = '\0';
}

void	end_quote(char *sig, char **s1, char **s2)
{
	if (*sig == '\"' || *sig == '\'')
	{
		if (**s1 == *sig)
			*sig = 1;
		*(*s2)++ = *(*s1)++;
	}
}

// int	is_redpipe(char c)
// {
// 	return (c == '<' || c == '>');
// }
