/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:54:55 by anda-cun          #+#    #+#             */
/*   Updated: 2023/09/12 17:27:01 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	void	*temp;
	int		total_size;

	total_size = size * nmemb;
	if (total_size > 2147483647)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	temp = ptr;
	while (total_size--)
		*(char *)ptr++ = '\0';
	return (temp);
}
/*
int	main()
{
	char	*ptr;
	int	nmemb = 10;
	int	i = 0;

	ptr = ft_calloc(nmemb, sizeof(char));
	while(nmemb--)
	{
		//printf("%d\t", i);
		write(1, &ptr[i], 1);
		i++;
	}
}*/
