/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 10:03:01 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 17:50:12 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_cmp(char const s1, char const *set)
{
	while (*set)
		if (*(set++) == s1)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	strlen;

	while (str_cmp(*s1, set))
		s1++;
	strlen = ft_strlen(s1);
	while (str_cmp(s1[strlen - 1], set))
		strlen--;
	return (ft_substr(s1, 0, strlen));
}
/*
int	main()
{
	printf("%s\n", ft_strtrim("", ""));
}*/
