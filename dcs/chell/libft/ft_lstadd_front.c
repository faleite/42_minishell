/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:54:51 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/23 21:26:31 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}
/*
int	main()
{
	t_list	**lst;
	t_list	*new;
	t_list *head;
	
	lst = malloc(sizeof(t_list));
	head = ft_lstnew("aaa");
	*lst = head;
	new = (t_list *)malloc(sizeof(t_list));
	new -> content = "ooo";
	ft_lstadd_front(lst, new);
	printf("head:\t%p\thead next: %p\n",head,head -> next);
	printf("new:\t%p\tnew next: %p\n",new,new -> next);
}*/
