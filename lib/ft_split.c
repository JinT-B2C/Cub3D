/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:39:05 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:39 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			count++;
			while (*str != c && *str)
				str++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	arr_len;
	char	**new_str;

	if (!s)
		return (0);
	i = 0;
	new_str = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!new_str)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			arr_len = 0;
			while (*s && *s != c && ++arr_len)
				s++;
			new_str[i++] = ft_substr(s - arr_len, 0, arr_len);
		}
		else
			s++;
	}
	new_str[i] = 0;
	return (new_str);
}
