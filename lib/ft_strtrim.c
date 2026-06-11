/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 09:30:02 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:56 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	begin = 0;
	end = ft_strlen(s1) - 1;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		++begin;
	while (s1[end] && ft_strchr(set, s1[end]))
		--end;
	i = (end - begin + 1);
	str = ft_substr(s1, begin, i);
	return (str);
}
