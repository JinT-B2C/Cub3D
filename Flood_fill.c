/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:23:04 by torasolo          #+#    #+#             */
/*   Updated: 2026/06/13 12:26:45 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static int	is_out_of_bounds(t_fill *fill, int x, int y)
{
	return (x < 0 || x >= fill->conf->map_width || y < 0
		|| y >= fill->conf->map_height);
}

static int	is_space_open(t_fill *fill, int x, int y)
{
	if (x == 0 || y == 0 || x == fill->conf->map_width - 1
		|| y == fill->conf->map_height - 1)
		return (0);
	if (fill->conf->map[y][x - 1] != '1' || fill->conf->map[y][x + 1] != '1'
		|| fill->conf->map[y - 1][x] != '1' || fill->conf->map[y + 1][x] != '1')
		return (0);
	return (1);
}

static int	push_point(t_fill *fill, int x, int y)
{
	if (fill->top >= fill->max)
		return (1);
	fill->stack[fill->top].x = x;
	fill->stack[fill->top].y = y;
	fill->top++;
	return (1);
}

static int	process_point(t_fill *fill, t_point cur)
{
	if (is_out_of_bounds(fill, cur.x, cur.y))
		return (0);
	if (fill->conf->map[cur.y][cur.x] == ' ' && !is_space_open(fill, cur.x,
			cur.y))
	{
		printf("Map is not enclosed at (%d, %d)\n", cur.x, cur.y);
		return (0);
	}
	if (fill->visited[cur.y][cur.x] == 'V'
		|| fill->conf->map[cur.y][cur.x] == '1')
		return (1);
	fill->visited[cur.y][cur.x] = 'V';
	push_point(fill, cur.x + 1, cur.y);
	push_point(fill, cur.x - 1, cur.y);
	push_point(fill, cur.x, cur.y + 1);
	push_point(fill, cur.x, cur.y - 1);
	return (1);
}

int	flood_fill(t_conf *conf, int sx, int sy, char **visited)
{
	t_point	cur;
	t_fill	fill;

	fill.conf = conf;
	fill.visited = visited;
	fill.max = conf->map_width * conf->map_height;
	fill.top = 0;
	fill.stack = malloc(sizeof(t_point) * fill.max);
	if (!fill.stack)
		return (0);
	push_point(&fill, sx, sy);
	while (fill.top > 0)
	{
		cur = fill.stack[--fill.top];
		if (!process_point(&fill, cur))
		{
			free(fill.stack);
			return (0);
		}
	}
	free(fill.stack);
	return (1);
}
