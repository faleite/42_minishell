/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:59:30 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 13:25:03 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	replace_var(t_pair *env, char *str)
{
	t_pair	*temp;
	char	*temp_str;

	temp = env;
	while (temp)
	{
		if (!ft_strncmp(str, temp->key, len_to_char(str, '=')))
		{
			if (!ft_strchr(temp->key, '='))
			{
				temp_str = temp->key;
				temp->key = ft_strjoin(temp_str, "=");
				free(temp_str);
			}
			free(temp->value);
			temp->value = ft_strdup(ft_strchr(str, '=') + 1);
		}
		temp = temp->next;
	}
	return (0);
}

t_pair	*copy_aux(t_pair *temp_export, t_pair *temp_env)
{
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
	return (temp_export);
}

t_pair	*copy_list_all(t_pair *env, t_pair *exported_vars)
{
	t_pair	*temp_env;
	t_pair	*temp_export;
	t_pair	*rtn;

	temp_export = malloc(sizeof(t_pair));
	rtn = temp_export;
	temp_env = env;
	temp_export = copy_aux(temp_export, temp_env);
	temp_env = exported_vars;
	temp_export->next = malloc(sizeof(t_pair));
	temp_export = temp_export->next;
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
	return (rtn);
}

int	print_sorted_all(t_pair *env, t_pair *exported_vars)
{
	t_pair	*export;
	t_pair	*temp_export;

	export = copy_list_all(env, exported_vars);
	sort_list(&export);
	temp_export = export;
	while (temp_export)
	{
		if (ft_strchr(temp_export->key, '='))
			printf("declare -x %s\"%s\"\n", temp_export->key,
				temp_export->value);
		else
			printf("declare -x %s%s\n", temp_export->key, temp_export->value);
		temp_export = temp_export->next;
	}
	free_pairs(export);
	return (0);
}
/*
If string doesn't start with an alphanum char or with a '_', return error
​
If string doesn't have a '='
	if string is not in env list && string is not in exported list
		add to exported list
​
If string has a '=':
	if string is in env list
		replace value
	else
		if string is in exported list
			replace string
		else
			add to exported list
	*/

int	export(t_data *data, char **str)
{
	int	i;

	i = -1;
	if (!*str)
		return (print_sorted_all(data->env, data->exported_vars));
	if (data->pipes.open)
		return (0);
	while (str[++i])
	{
		if (!ft_isalpha(*str[i]))
			return (print_export_error(data, str[i]));
		if (!is_valid(str[i]))
			return (print_export_error(data, str[i]));
		if (!ft_strchr(str[i], '=') && (!check_dupes(data->env, str[i])
				&& !check_dupes(data->exported_vars, str[i])))
			add_to_list(str[i], data->exported_vars);
		else if (ft_strchr(str[i], '=') && check_dupes(data->env, str[i]))
			replace_var(data->env, str[i]);
		else if (ft_strchr(str[i], '=') && check_dupes(data->exported_vars,
				str[i]))
			replace_var(data->exported_vars, str[i]);
		else if (ft_strchr(str[i], '='))
			add_to_list(str[i], data->exported_vars);
	}
	return (0);
}
