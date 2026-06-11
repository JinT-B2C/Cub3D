/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:32:10 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:54 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr_big;
	char	*ptr_little;

	i = 0;
	ptr_big = ((char *)big);
	ptr_little = ((char *)little);
	if (*ptr_little == '\0')
		return (ptr_big);
	while (ptr_big[i] != '\0')
	{
		j = 0;
		while (ptr_big[i + j] == ptr_little[j] && ptr_little[j] != '\0' && (
				j + i < len))
			j++;
		if (ptr_little[j] == '\0')
			return (&ptr_big[i]);
		i++;
	}
	return (0);
}
