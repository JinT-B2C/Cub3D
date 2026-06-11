/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:02:41 by torasolo          #+#    #+#             */
/*   Updated: 2026/03/16 09:14:08 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *neww)
{
	t_list	*list;

	list = *lst;
	if (!lst || !neww)
		return ;
	if (*lst == NULL)
	{
		*lst = neww;
		return ;
	}
	while (list -> next != NULL)
		list = list -> next;
	list -> next = neww;
}
