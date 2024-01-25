/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feden-pe <feden-pe@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:08:36 by feden-pe          #+#    #+#             */
/*   Updated: 2024/01/25 18:31:14 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/executor.h"

t_envp	*getev(void)
{
	static t_envp envp;

	return (&envp);
}

void	ft_envp(char *envp[])
{
	int		i;
	int		len_e;

	i = 0;
	while (envp[i])
		i++;
	getev()->envp = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (envp[i])
	{
		getev()->envp[i] = ft_strdup(envp[i]);
		i++;
	}
}


int	main(int ac, char **av, char **ev)
{
	int	i = 0;
	ft_envp(ev);
	char **temp;
	temp = getev()->envp;
	while (temp[i])
		printf("%s\n", getev()->envp[i++]);
	i = 0;
	while (getev()->envp[i])
		free(getev()->envp[i++]);
	free(getev()->envp);

	return (0);
}
