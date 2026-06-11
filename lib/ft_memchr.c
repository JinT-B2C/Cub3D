/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:39:15 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/24 09:27:58 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = -1;
	while (n > ++i)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((unsigned char *)s)[i]);
	}
	return (0);
}
