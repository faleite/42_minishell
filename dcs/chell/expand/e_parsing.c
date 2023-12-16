/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:18:30 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/10 13:26:13 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_exported(t_data *data, char *temp1)
{
	t_pair	*temp;

	temp = data->exported_vars;
	while (temp)
	{
		if (*(temp1 + 1) && !ft_strncmp(&temp1[1], temp->key,
				ft_strlen(&temp1[1])))
			return (c_strdup(temp->value, temp1));
		else if (*(temp1 + 1) && *(temp1 + 1) == '?')
		{
			free(temp1);
			return (ft_itoa(data->exit_status));
		}
		temp = temp->next;
	}
	free(temp1);
	return (NULL);
}

char	*search_key(t_data *data, char *str)
{
	t_pair	*temp;
	char	*temp1;

	temp = data->env;
	if (!*(str + 1))
		return (c_strdup("$", str));
	temp1 = ft_append(str, '=');
	while (temp)
	{
		if (*(temp1 + 1) && !ft_strncmp(&temp1[1], temp->key,
				ft_strlen(&temp1[1])))
			return (c_strdup(temp->value, temp1));
		else if (*(temp1 + 1) && *(temp1 + 1) == '?')
		{
			free(temp1);
			return (ft_itoa(data->exit_status));
		}
		temp = temp->next;
	}
	return (search_exported(data, temp1));
}

char	*solve_expansion(t_data *data, char *temp, int c)
{
	int		i;
	char	*final;
	char	**trying;
	char	flag;

	flag = 0;
	final = NULL;
	temp[c] = '\0';
	i = -1;
	trying = ft_split(temp, 1);
	free(temp);
	while (trying[++i] != NULL)
	{
		if (ft_strchr(trying[i], '$') && flag != '\'')
			final = c_strjoin(final, search_key(data, trying[i]));
		else if (parse(trying, i, &flag))
			final = c_strjoin(final, trying[i]);
		else
		{
			final = c_strjoin(final, NULL);
			free(trying[i]);
		}
	}
	free(trying);
	return (final);
}

char	*f_expans(t_data *data, t_arg *arg, int i, int c)
{
	char	*temp;

	temp = malloc(ft_strlen(arg->token) * 3 + 1);
	while (arg->token[++i] != '\0')
	{
		if (i > 0 && arg->token[i - 1] == '$' && arg->token[i] == '?')
		{
			temp[c++] = arg->token[i];
			temp[c++] = 1;
		}
		else if (arg->token[i] == '$' && i > 0)
		{
			temp[c++] = 1;
			temp[c++] = arg->token[i];
		}
		else if (should_break(arg, i))
		{
			temp[c++] = 1;
			temp[c++] = arg->token[i];
			temp[c++] = 1;
		}
		else
			temp[c++] = arg->token[i];
	}
	return (solve_expansion(data, temp, c));
}

void	expand_struct(t_data *data, t_command_list *cmd_lst)
{
	int		i;
	char	*temp;

	i = -1;
	while (cmd_lst)
	{
		while (cmd_lst->arg[++i].token != NULL)
		{
			temp = cmd_lst->arg[i].token;
			cmd_lst->arg[i].token = f_expans(data, &(cmd_lst->arg[i]), -1, 0);
			if (!ft_strncmp(cmd_lst->arg[i].token, "",
					ft_strlen(cmd_lst->arg[i].token)) && temp[0] == '$')
				cmd_lst->arg[i].type = -10;
			free(temp);
		}
		i = -1;
		cmd_lst = cmd_lst->next;
	}
}
