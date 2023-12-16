/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:03:39 by anda-cun          #+#    #+#             */
/*   Updated: 2023/04/26 14:32:28 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_lstnew(f(lst -> content));
	if (!newlist)
		return (NULL);
	ptr = newlist;
	lst = lst -> next;
	while (lst)
	{
		newlist -> next = ft_lstnew(f(lst -> content));
		if (!newlist -> next)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		newlist = newlist -> next;
		lst = lst -> next;
	}
	newlist -> next = NULL;
	return (ptr);
}
