/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:42:39 by feden-pe          #+#    #+#             */
/*   Updated: 2024/01/18 19:06:39 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

char	*var_path(char *envp[])
{
	char	*path;
	int	i;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;;
			return (path);
		}
		i++;
	}
	return (path);
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

char	*cmd_path(char *envp[], char *cmd)
{
	char	**path_cmds;
	char	*path;
	int	p_len;
	int	c_len;
	
	if (access(cmd, F_OK) == 0)
		return (cmd);
	path_cmds = ft_split(var_path(envp), ':');
	path = NULL;
	while (*path_cmds)
	{
		p_len = ft_strlen(*path_cmds);
		c_len = ft_strlen(cmd);
		path = malloc(sizeof(char) * (p_len + c_len + 2));
		if (!path)
			return (NULL);
		if (access(create_path(path, *path_cmds, cmd), F_OK) == 0)
			return (path);
		free(path);
		path_cmds++;
	}
	return (NULL);
}
