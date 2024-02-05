/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:57:33 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 12:47:37 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	print_export_error(t_data *data, char *str)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd("': not a valid identifier", 2);
	data->exit_status = 1;
	return (0);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) || str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	check_dupes(t_pair *env, char *str)
{
	t_pair	*temp;
	int		str_size;

	if (!env || !env->key)
	{
		return (0);
	}
	temp = env;
	str_size = len_to_char(str, '=');
	while (temp)
	{
		if (!ft_strncmp(str, temp->key, str_size) && (!temp->key[str_size]
				|| temp->key[str_size] == '='))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	add_to_list(char *str, t_pair *exported_vars)
{
	t_pair	*temp;

	temp = exported_vars;
	if (temp->key)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = malloc(sizeof(t_pair));
		temp = temp->next;
	}
	if (!ft_strchr(str, '='))
	{
		temp->key = ft_strdup(str);
		temp->value = NULL;
	}
	else
	{
		temp->key = ft_substr(str, 0, len_to_char(str, '=') + 1);
		temp->value = ft_strdup(ft_strchr(str, '=') + 1);
	}
	temp->next = NULL;
	return (0);
}
