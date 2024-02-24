/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 02:37:04 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/24 15:58:48 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_len(char *str, int len)
{
	if (len > 20 || len < 1)
		return (0);
	if (len == 19)
	{
		if (ft_strncmp(str, "9223372036854775807", 20) > 0)
			return (0);
		if (ft_strncmp(str, "-9223372036854775808", 20) > 0)
			return (0);
	}
	return (1);
}

int	is_num(char *str)
{
	int	flag;

	flag = 0;
	if (*str == '-')
		str++;
	while (*str)
	{
		flag = 1;
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (flag);
}

int	is_long(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	if (!check_len(str, len))
		return (0);
	if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
	{
		data()->exit_status = 2;
		return (0);
	}
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
		{
			data()->exit_status = 2;
			return (0);
		}
	}
	return (1);
}

int	in_str(char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			flag = 1;
		i++;
	}
	return (flag);
}

void	export_keys(char **key_value, char *name, int i)
{
	t_envp	*new_node;
	t_envp	*existing;

	if (node_exists(name) && get_value(name))
		update_value(name, add_value(key_value[i]));
	else if (node_exists(name) && in_str(key_value[i], '='))
	{
		existing = get_node(name);
		free(existing->value);
		existing->value = ft_strdup(add_value(key_value[i]));
	}
	else if (in_str(key_value[i], '='))
	{
		new_node = insert_end_envp(&data()->envp);
		new_node->name = ft_strdup(name);
		new_node->value = ft_strdup(add_value(key_value[i]));
	}
	else if (!in_str(key_value[i], '='))
	{
		new_node = insert_end_envp(&data()->envp);
		new_node->name = ft_strdup(name);
		new_node->value = NULL;
	}
	data()->exit_status = 0;
}
