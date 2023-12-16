/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:11:39 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 16:59:18 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((unsigned char) c == '\0')
		return ((char *) &s[i]);
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	char *str = "e";
	printf("%s\n", ft_strrchr(str, 'e'));
}*/
