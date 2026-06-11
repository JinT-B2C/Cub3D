/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 03:15:06 by torasolo          #+#    #+#             */
/*   Updated: 2026/06/11 03:16:59 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	get_map_width(char **lines, int start)
{
	int	max_width;
	int	len;

	max_width = 0;
	while (lines[start] && !is_line_empty(lines[start]))
	{
		len = ft_strlen(lines[start]);
		if (len > 0 && lines[start][len - 1] == '\n')
			len--;
		if (len > max_width)
			max_width = len;
		start++;
	}
	return (max_width);
}

int	get_map_height(char **lines, int start)
{
	int	height;

	height = 0;
	while (lines[start + height] && !is_line_empty(lines[start + height]))
		height++;
	return (height);
}
