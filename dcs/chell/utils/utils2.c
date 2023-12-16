/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:00:23 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/08 12:23:43 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_pair	*copy_list(t_pair *env)
{
	t_pair	*temp_env;
	t_pair	*export;
	t_pair	*temp_export;

	export = malloc(sizeof(t_pair));
	temp_export = export;
	temp_env = env;
	while (temp_env)
	{
		temp_export->key = ft_strdup(temp_env->key);
		temp_export->value = ft_strdup(temp_env->value);
		temp_env = temp_env->next;
		if (temp_env)
		{
			temp_export->next = malloc(sizeof(t_pair));
			temp_export = temp_export->next;
		}
		else
			temp_export->next = NULL;
	}
	return (export);
}

void	sort_list(t_pair **export)
{
	t_pair	*cur;
	t_pair	*next;
	char	*temp;

	cur = *export;
	next = cur->next;
	while (cur && next)
	{
		if (ft_strncmp(cur->key, next->key, ft_strlen(cur->key)) > 0)
		{
			temp = cur->key;
			cur->key = next->key;
			next->key = temp;
			temp = cur->value;
			cur->value = next->value;
			next->value = temp;
			cur = *export;
			next = cur->next;
		}
		else
		{
			cur = cur->next;
			next = cur->next;
		}
	}
}
