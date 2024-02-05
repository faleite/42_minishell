/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:37:31 by anda-cun          #+#    #+#             */
/*   Updated: 2023/07/04 15:35:40 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
	{
		if (fd >= 0 && fd <= FOPEN_MAX)
			ft_clean_buf(buf[fd]);
		return (NULL);
	}
	while (buf[fd][0] || read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin_gnl(str, buf[fd]);
		if (ft_move_and_clean(buf[fd]))
			break ;
	}
	return (str);
}
