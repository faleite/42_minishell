/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:24:15 by anda-cun          #+#    #+#             */
/*   Updated: 2023/07/04 15:01:16 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	if (!*lst)
		return ;
	curr = *lst;
	while (curr->next)
	{
		next = curr->next;
		ft_lstdelone(curr, del);
		curr = next;
	}
	ft_lstdelone(curr, del);
	*lst = NULL;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list **lst;
	t_list *l1, *l2, *l3, *l4;

	l1 = ft_lstnew("aaa");
	l2 = ft_lstnew("eee");
	l3 = ft_lstnew("iii");
	l4 = ft_lstnew("uuu");
	printf("%p\t%p\t%p\t%p\n", l1, l2, l3, l4);
	printf("%s\t%s\t%s\t%s\n", l1 -> content, l2 -> content, l3 -> content);
	lst = malloc(sizeof(t_list));
	*lst = l3;
	ft_lstadd_front(lst, l2);
	ft_lstadd_front(lst, l1);
	printf("%d\n", ft_lstsize(*lst));
	ft_lstadd_back(lst, l4);
	printf("%s, %s\n", (ft_lstlast(*lst) -> content), ft_lstlast(*lst) -> next);
	ft_lstclear(lst, del);
	free(lst);
	//printf("last %s\n", *lst);
}*/
