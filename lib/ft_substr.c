/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:30:27 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:57 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	src_len;

	if (!s)
		return (0);
	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	if ((src_len - start) < len)
		len = src_len - start;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	ft_strlcpy(new_str, s + start, len + 1);
	return (new_str);
}
