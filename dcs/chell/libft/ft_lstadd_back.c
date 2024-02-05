/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:09 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 21:44:42 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)-> next = new;
	else
		*lst = new;
}
/*
#include <stdio.h>
int	main()
{
	t_list **lst;
	t_list *l1, *l2, *l3, *l4;

	l1 = ft_lstnew("aaa");
	l2 = ft_lstnew("eee");
	l3 = ft_lstnew("iii");
	l4 = ft_lstnew("uuu");
	lst = malloc(sizeof(t_list));
	*lst = l3;
	ft_lstadd_front(lst, l2);
	ft_lstadd_front(lst, l1);
	printf("%d\n", ft_lstsize(*lst));
	ft_lstadd_back(lst, l4);
	printf("%s\n", ((char *)ft_lstlast(*lst) -> content));
}*/
