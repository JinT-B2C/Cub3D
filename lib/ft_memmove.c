/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:37:55 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:28 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*ptr_s;
	unsigned char		*ptr_d;

	if (!dest && !src)
		return (dest);
	ptr_s = src;
	ptr_d = dest;
	if (ptr_d > ptr_s)
	{
		ptr_d = ptr_d + n - 1;
		ptr_s = ptr_s + n - 1;
		while (n > 0)
		{
			*(ptr_d--) = *(ptr_s--);
			n--;
		}
	}
	while (n > 0)
	{
		*(ptr_d++) = *(ptr_s++);
		n--;
	}
	return (dest);
}
