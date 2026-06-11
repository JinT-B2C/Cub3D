/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:43:37 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:15 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nw_head;

	if (!lst || !f || !del)
		return (NULL);
	nw_head = ft_lstnew(f(lst -> content));
	if (nw_head == NULL)
		return (NULL);
	new = nw_head;
	while (lst && lst -> next)
	{
		if (!new)
		{
			ft_lstclear(&nw_head, del);
			return (NULL);
		}
		new -> next = ft_lstnew(f(lst -> next -> content));
		new = new -> next;
		lst = lst -> next;
	}
	return (nw_head);
}
