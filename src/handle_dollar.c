/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:44:44 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/28 21:17:07 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	g_status;

int	dollar(char **src, char **dst, int i)
{
	char	*start;
	char	*end;
	char	*var;
	char	*value;

	start = ++(*src);
	while (**src != ' ' && **src != '\2' && **src != '\'' && \
			**src != '\"' && **src)
		(*src)++;
	end = *src;
	var = (char *)malloc(sizeof(char) * ((end - start) + 1));
	ft_strlcpy(var, start, ((end - start) + 1));
	//Lidar com $? aqui em var;
	value = getenv(var);
	if (value)
	{
		ft_strlcpy(*dst + i, value, (ft_strlen(*src) + ft_strlen(value) + 1));
		i += ft_strlen(value);
	}
	free (var);
	return (i);
}

void	ctrlc_sigint(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}