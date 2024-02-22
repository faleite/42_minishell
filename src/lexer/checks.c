/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:59:24 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/22 22:17:38 by faaraujo         ###   ########.fr       */
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

char	*str_spaces_end(char *str)
{
	int		end;
	char	*cpy;

	cpy = ft_strdup(str);
	end = ft_strlen(str) - 1;
	while (end > 0 && white_space(cpy[end]))
	{
		cpy[end] = '\0';
		end--;
	}
	return (cpy);
}
