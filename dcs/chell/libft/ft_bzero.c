/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:29:25 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 15:20:45 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char *)s++) = '\0';
}
/*
#include <stdio.h>
int	main()
{
	int	i = 0;
	char *str = "Hello";
	int	size = ft_strlen(str);
	printf("%s\n", str);
	bzero(str, 3*sizeof(char));
	printf("%s\n", str);
}*/
