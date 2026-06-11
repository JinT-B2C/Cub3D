/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:57:22 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:55 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		j;
	char	*cast;

	i = 0;
	cast = (char *)str;
	while (cast[i] != '\0')
		i++;
	j = i;
	while (j >= 0)
	{
		if (cast[j] == (char)c)
			return (&cast[j]);
		j--;
	}
	return (NULL);
}
