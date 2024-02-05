/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:29:35 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 21:28:23 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}
/*
#include <stdio.h>

int	main()
{
	t_list	**lst;
	t_list	*l1, *l2;

	lst = malloc(sizeof(t_list));
	l1 = ft_lstnew("ya");
	*lst = l1;
	l2 = ft_lstnew("oy");
	ft_lstadd_front(lst, l2);
	printf("lst:\t%p\n", *lst); 
	printf("l2:\t%p\tl2 next: %p\n",l2,l2 -> next); 
	printf("l1:\t%p\tl1 next: %p\n",l1,l1 -> next);
	printf("%d\n", ft_lstsize(*lst));
}*/
