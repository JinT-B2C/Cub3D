/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:57:05 by torasolo          #+#    #+#             */
/*   Updated: 2026/05/17 21:33:06 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int nb, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)ptr)[i] = nb;
		i++;
	}
	return (ptr);
}
