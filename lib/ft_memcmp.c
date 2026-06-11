/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:24:11 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:24 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pt_s1;
	unsigned char	*pt_s2;

	i = 0;
	pt_s1 = ((unsigned char *)s1);
	pt_s2 = ((unsigned char *)s2);
	while (i < n)
	{
		if (pt_s1[i] != pt_s2[i])
			return (pt_s1[i] - pt_s2[i]);
		i++;
	}
	return (0);
}
