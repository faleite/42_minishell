/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eportela <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:57:32 by eportela          #+#    #+#             */
/*   Updated: 2023/09/30 15:57:32 by eportela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token(char *line)
{
	if (!line || *line == '\0')
		return (STR);
	if (line[0] == '|')
		return (PIPE);
	if (line[0] == '>')
	{
		if (line[1] && line[1] == '>')
			return (APPEND);
		else
			return (OUT);
	}
	if (line[0] == '<')
	{
		if (line[1] && line[1] == '<')
			return (HEREDOC);
		else
			return (IN);
	}
	if (line[0] == ';')
		return (END);
	else
		return (STR);
}

int	ft_strleni(char **splitter, int i)
{
	int	size;

	size = 0;
	while (splitter[i] && !z_cmp(splitter[i++], "|"))
		size++;
	return (size);
}
