/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 03:12:37 by torasolo          #+#    #+#             */
/*   Updated: 2026/06/11 03:27:23 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static int	check_player(t_conf *conf, int x, int y, char c)
{
	if (conf->player_or != '\0')
		return (0);
	conf->player_x = x;
	conf->player_y = y;
	conf->player_or = c;
	return (1);
}

static char	**create_visited(t_conf *conf)
{
	char	**visited;
	int		i;

	visited = malloc(sizeof(char *) * conf->map_height);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < conf->map_height)
	{
		visited[i] = ft_calloc(conf->map_width + 1, sizeof(char));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}

static void	free_visited(char **visited, int height)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}

static int	handle_cell(t_conf *conf, int x, int y, int *player_count)
{
	char	c;

	c = conf->map[y][x];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (!check_player(conf, x, y, c))
			return (0);
		(*player_count)++;
		conf->map[y][x] = '0';
	}
	else if (c != '0' && c != '1' && c != ' ')
		return (0);
	return (1);
}

int	validate_map(t_conf *conf)
{
	int		x;
	int		y;
	int		player_count;
	char	**visited;

	player_count = 0;
	y = -1;
	while (++y < conf->map_height)
	{
		x = -1;
		while (++x < conf->map_width)
		{
			if (!handle_cell(conf, x, y, &player_count))
				return (0);
		}
	}
	if (player_count != 1)
		return (0);
	visited = create_visited(conf);
	if (!visited)
		return (0);
	if (!flood_fill(conf, conf->player_x, conf->player_y, visited))
		return (free_visited(visited, conf->map_height), 0);
	free_visited(visited, conf->map_height);
	return (1);
}
