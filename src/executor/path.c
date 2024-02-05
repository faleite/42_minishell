/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:42:39 by feden-pe          #+#    #+#             */
/*   Updated: 2024/02/05 20:05:39 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

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

char	*cmd_path(char *cmd)
{
	char	**path_cmds;
	char	**tmp;
	char	*path;
	int		p_len;
	int		c_len;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	path_cmds = ft_split(data()->path, ':');
	path = NULL;
	tmp = path_cmds;
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
	free_arr(tmp);
	return (NULL);
}
