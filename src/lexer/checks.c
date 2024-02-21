/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:59:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/20 22:21:02 by faaraujo         ###   ########.fr       */
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

char	*str_spaces_end(char *str)
{
	char	*cpy;
	int 	end;

	cpy = ft_strdup(str);
	end = ft_strlen(str) - 1;
	while (end > 0 && white_space(cpy[end]))
	{
		cpy[end] = '\0';
		end--;
	}
	return (cpy);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*cpy;

// 	str = "ola    \t     \t";
// 	cpy = str_spaces_end(str);
// 	printf("%s\n", cpy);
// 	free(cpy);
// 	return (0);
// }
