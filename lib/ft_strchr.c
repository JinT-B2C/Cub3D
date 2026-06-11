/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:43:25 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:40 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cast;

	i = 0;
	cast = ((char *)s);
	while (cast[i] != '\0')
	{
		if (cast[i] == (char)c)
			return (&cast[i]);
		i++;
	}
	if (cast[i] == (char)c)
		return (&cast[i]);
	return (0);
}
