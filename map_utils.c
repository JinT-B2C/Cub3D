/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:35:46 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/11 03:17:50 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static void	free_map_partial(char **map, int count)
{
	while (--count >= 0)
		free(map[count]);
	free(map);
}

static int	allocate_map(char ***map_ptr, int height, int width)
{
	int		i;
	char	**map;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (0);
	i = 0;
	while (i < height)
	{
		map[i] = ft_calloc(width + 1, sizeof(char));
		if (!map[i])
		{
			free_map_partial(map, i);
			return (0);
		}
		i++;
	}
	map[height] = NULL;
	*map_ptr = map;
	return (1);
}

static void	fill_row(char *dest, const char *src, int width)
{
	int	j;

	j = 0;
	while (j < width && src[j] && src[j] != '\n')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < width)
		dest[j++] = ' ';
	dest[width] = '\0';
}

int	build_map(char **lines, t_conf *conf, int start_line)
{
	char	**map;
	int		width;
	int		height;
	int		i;

	width = get_map_width(lines, start_line);
	height = get_map_height(lines, start_line);
	if (width <= 0 || height <= 0)
		return (0);
	if (!allocate_map(&map, height, width))
		return (0);
	i = 0;
	while (i < height)
	{
		fill_row(map[i], lines[start_line + i], width);
		i++;
	}
	conf->map = map;
	conf->map_width = width;
	conf->map_height = height;
	return (1);
}
