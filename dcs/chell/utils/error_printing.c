/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:54:19 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 13:31:26 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	print_file_error(char *s1, char *s2)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	return (2);
}

int	print_syntax_error(t_data *data, char c)
{
	data->exit_status = 2;
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (!c)
		ft_putstr_fd("newline", 2);
	else
		ft_putchar_fd(c, 2);
	ft_putendl_fd("'", 2);
	return (2);
}
