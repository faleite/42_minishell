/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:59:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/19 21:05:07 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	white_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	just_spaces(char *str)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	while (str[i])
	{
		if (white_space(str[i]))
			spaces++;
		i++;
	}
	return (ft_strlen(str) - spaces);
}

int	is_dollar_quotes(char c)
{
	return (c == '\2' || c == '\'' || \
			c == '\"' || c == '$' );
}

int	print_dollar(char c)
{
	return (c == '/' || c == '.' || c == ',' || c == '%' || \
			c == ':' || c == '=' || c == ';' || c == ')' || \
			c == '+' || c == ']' || c == '}' || c == '!' || \
			c == '~' || c == '^' || c == '|'); 
}
