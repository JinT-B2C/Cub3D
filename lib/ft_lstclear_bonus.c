/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:28:09 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:08 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*after;

	after = NULL;
	if (lst)
	{
		while (*lst)
		{
			after = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = after;
		}
		free(*lst);
		*lst = NULL;
	}
}
