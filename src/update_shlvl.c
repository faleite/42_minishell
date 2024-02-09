/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:03:53 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/09 18:23:58 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*etoa(char *name, char *value)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc(ft_strlen(name) + ft_strlen(value) + 2, sizeof(char));
	while (name[i])
	{
		new[i] = name[i];
		i++;
	}
	new[i] = '=';
	i = 0;
	while (value[i])
	{
		new[i] = value[i];
		i++;
	}
	return (new);
}

char	**update_env(void)
{
	t_envp	*current;
	int		i;
	char	**new;

	i = 0;
	current = data()->envp;
	while (current && current->name)
	{
		i++;
		current = current->next;
	}
	new = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	current = data()->envp;
	while (current)
	{
		new[i] = etoa(current->name, current->value);
		i++;
		current = current->next;
	}
	new[i] = NULL;
	return (new);
}

void	update_shlvl(char **envp)
{
	int		i;
	int		shlvl;
	char	*new;

	i = 0;
	while (ft_strncmp(envp[i], "SHLVL", 5))
		i++;
	new = ft_substr(envp[i], 6, ft_strlen(envp[i]));
	shlvl = ft_atoi(new);
	free(new);
	free(envp[i]);
	new = ft_itoa(shlvl + 1);
	envp[i] = ft_strjoin("SHLVL=", new);
	free(new);
}

void	no_envp(void)
{
	char	*pwd;
	char	**tmp;

	pwd = getcwd(NULL, 0);
	tmp = ft_calloc(3, sizeof(char *));
	tmp[0] = ft_strjoin("PWD=", pwd);
	tmp[1] = ft_strdup("SHLVL=1");
	free(pwd);
	getevarr()->envp = tmp;
}

void	new_envp(char **envp)
{
	t_envp	*getev;
	char	**tmp;

	getev = NULL;
	if (!envp || !envp[0])
	{
		no_envp();
		fill_envp(&getev, getevarr()->envp);
		data()->envp = getev;
	}
	else
	{
		tmp = envp_exec(envp);
		getevarr()->envp = tmp;
		update_shlvl(getevarr()->envp);
		fill_envp(&getev, getevarr()->envp);
		data()->envp = getev;
	}
}
