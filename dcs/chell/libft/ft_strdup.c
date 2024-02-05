/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:09:37 by anda-cun          #+#    #+#             */
/*   Updated: 2023/07/07 13:01:06 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		length;
	int		i;

	length = ft_strlen(s);
	i = 0;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	while (s && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[length] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*src = "source";
	char	*dest = ft_strdup(src);
	printf("%p\t%p\n", src, dest);
}*/
