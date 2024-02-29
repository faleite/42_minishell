/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:42:39 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/29 18:33:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*var_path(void)
{
	t_envp	*current;

	current = data()->envp;
	while (current)
	{
		if (!ft_strncmp(current->name, "PATH", 4))
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

char	*create_path(char *dest, char *path, char *command)
{
	int	i;

	i = 0;
	if (!path || !command)
		return (NULL);
	while (*path)
		dest[i++] = *path++;
	dest[i++] = '/';
	while (*command)
		dest[i++] = *command++;
	dest[i++] = '\0';
	return (dest);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	*get_path(char **path_cmds, char **tmp, char *path, char *cmd)
{
	int	p_len;
	int	c_len;

	while (*path_cmds)
	{
		p_len = ft_strlen(*path_cmds);
		c_len = ft_strlen(cmd);
		path = malloc(sizeof(char) * (p_len + c_len + 2));
		if (!path)
			return (NULL);
		if (access(create_path(path, *path_cmds, cmd), F_OK) == 0)
		{
			free_arr(tmp);
			return (path);
		}
		free(path);
		path_cmds++;
	}
	return (NULL);
}

char	*cmd_path(char *cmd)
{
	char	**path_cmds;
	char	**tmp;
	char	*path;

	if (access(cmd, F_OK | X_OK) == 0 && \
		(!ft_strncmp(cmd, "./", 2) || !ft_strncmp(cmd, "/", 1)))
		return (ft_strdup(cmd));
	path_cmds = ft_split(data()->path, ':');
	path = NULL;
	tmp = path_cmds;
	path = get_path(path_cmds, tmp, path, cmd);
	if (path != NULL)
		return (path);
	free_arr(tmp);
	return (path);
}
