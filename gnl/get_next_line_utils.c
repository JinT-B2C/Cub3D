/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:28:44 by torasolo          #+#    #+#             */
/*   Updated: 2026/04/07 23:15:19 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*strchr_gnl(const char *s, int c)
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

void	*calloc_gnl(size_t nmemb, size_t size)
{
	size_t	total;
	size_t	i;
	char	*ptr;

	i = -1;
	total = nmemb * size;
	ptr = malloc(sizeof(char) * total);
	if (!ptr)
		return (NULL);
	while (++i < total)
		ptr[i] = 0;
	return (ptr);
}

size_t	strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = strlen_gnl(src);
	if (size)
	{
		while (size-- > 1 && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len);
}

char	*strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (strlen_gnl(s1) + strlen_gnl(s2) + 1));
	if (!str)
		return (str);
	strlcpy_gnl(str, s1, strlen_gnl(s1) + 1);
	strlcpy_gnl(str + strlen_gnl(s1), s2, strlen_gnl(s2) + 1);
	return (str);
}
