/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:01 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 15:40:00 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief returns 2 if the string has unclosed quotes or parenthesis;
 *
 * @param str
 * @return int
 */

#include "minishell.h"

int	check_end_of_command(t_data *data, char *str)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	i--;
	while (i > 0 && str[i] && str[i] != '\'' && str[i] != '"')
	{
		while (str[i] == ' ')
			i--;
		if (!str[i])
			break ;
		if (ft_strchr("<>|", str[i]))
			return (print_syntax_error(data, str[i + 1]));
		break ;
	}
	return (0);
}

int	check_pipes(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '|')
		return (1);
	return (0);
}

int	check_unexpected_token(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && ft_strchr("<>|", str[i]))
		return (print_syntax_error(data, str[i]));
	return (0);
}

int	token_error(t_data *data, char *str, int *i)
{
	int	j;

	while (str[*i] && str[*i] != '\'' && str[*i] != '"')
	{
		j = 0;
		if (str[*i] == ';')
			return (print_syntax_error(data, str[*i]));
		if (!ft_strncmp(&str[*i], "<<", 2) || !ft_strncmp(&str[*i], ">>", 2))
			j += 2;
		else if (ft_strchr("<>", str[*i]))
			j += 1;
		if (j && check_unexpected_token(data, &str[*i + j]))
			return (2);
		else if (str[*i] == '|')
			if (check_pipes(&str[*i + 1]))
				return (print_syntax_error(data, str[*i]));
		(*i)++;
	}
	return (0);
}

/*
Checks parsing errors in input string
First evaluates if there are token errors
	if string starts with a pipe
	if after a special token (<<, >>, < or >) there is another special token (<,
		>, |);
Then checks if there are unclosed quotes.
Loops while str[i] exists;
Finally checks if there is a special character at the end of the command
*/

int	check_parse_errors(t_data *data, char *str, int i)
{
	char	c;

	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] == '|')
		return (print_syntax_error(data, str[i]));
	while (str[i])
	{
		c = 0;
		if (token_error(data, str, &i))
			return (1);
		if (str[i])
		{
			c = str[i++];
			while (str[i] && str[i] != c)
				i++;
			if (!str[i])
				return (print_syntax_error(data, c));
		}
		else
			break ;
		i++;
	}
	return (check_end_of_command(data, str));
}
