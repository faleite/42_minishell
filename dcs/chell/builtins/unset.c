/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:43:40 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 13:01:38 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	len_to_char(char *str, char c)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
	{
		if (str[len] == c)
			return (len);
		len++;
	}
	return (len);
}

int	remove_aux(t_pair *cur, t_pair *prev)
{
	free(cur->key);
	cur->key = NULL;
	free(cur->value);
	cur->value = NULL;
	if (!prev)
	{
		prev = cur;
		if (prev->next)
		{
			cur = cur->next;
			free(prev);
		}
		prev = NULL;
		return (1);
	}
	return (0);
}

int	remove_from_list(char *str, t_pair *pair)
{
	t_pair	*cur;
	t_pair	*prev;

	cur = pair;
	prev = NULL;
	while (cur)
	{
		if (!ft_strncmp(str, cur->key, ft_strlen(str))
			&& (!cur->key[ft_strlen(str)] || cur->key[ft_strlen(str)] == '='))
		{
			if (!remove_aux(cur, prev))
			{
				prev->next = cur->next;
				if (cur->next)
					free(cur);
			}
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}

int	unset(t_data *data, char **str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if ((!ft_isalnum(*str[i]) && *str[i] != '_') || ft_strchr(str[i], '='))
		{
			ft_putstr_fd("unset: ", 2);
			ft_putstr_fd(str[i], 2);
			ft_putendl_fd(": invalid parameter name", 2);
		}
		else if (!remove_from_list(str[i], data->env))
		{
			if (data->exported_vars->key)
				remove_from_list(str[i], data->exported_vars);
		}
	}
	return (0);
}
