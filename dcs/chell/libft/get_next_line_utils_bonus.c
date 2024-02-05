/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:27:12 by anda-cun          #+#    #+#             */
/*   Updated: 2023/07/07 09:39:58 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

size_t	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)
				+ 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		str[i + j++] = '\n';
	str[i + j] = '\0';
	free(s1);
	return (str);
}

int	ft_move_and_clean(char *buf)
{
	int	i;
	int	nl;
	int	j;

	j = 0;
	i = 0;
	nl = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			nl = 1;
			i++;
			break ;
		}
		i++;
	}
	while (buf[i])
		buf[j++] = buf[i++];
	ft_clean_buf(&buf[j]);
	return (nl);
}

void	ft_clean_buf(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
		buf[i] = 0;
}
