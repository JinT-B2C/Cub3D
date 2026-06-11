/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:36:07 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/11 03:44:50 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static int	grow_map(char ***map_ptr, int count, int *capacity)
{
	char	**tmp;
	size_t	size;

	size = sizeof(char *) * (*capacity * 2 + 1);
	tmp = malloc(size);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *map_ptr, sizeof(char *) * count);
	free(*map_ptr);
	*map_ptr = tmp;
	*capacity *= 2;
	return (1);
}

static char	**cleanup_on_error(int fd, char *line, char **map)
{
	free(line);
	free_lines(map);
	close(fd);
	return (NULL);
}

static char	**alloc_initial_map(int capacity)
{
	char	**map;

	map = malloc(sizeof(char *) * (capacity + 1));
	return (map);
}

static char	**read_lines(int fd, char **map, int *count, int *capacity)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*count >= *capacity)
		{
			if (!grow_map(&map, *count, capacity))
				return (cleanup_on_error(fd, line, map));
		}
		map[(*count)++] = line;
	}
	return (map);
}

char	**read_map(const char *path)
{
	int		fd;
	char	**map;
	int		count;
	int		capacity;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	capacity = 32;
	map = alloc_initial_map(capacity);
	if (!map)
		return (close(fd), NULL);
	count = 0;
	map = read_lines(fd, map, &count, &capacity);
	if (!map)
		return (NULL);
	close(fd);
	if (count == 0)
		return (free(map), NULL);
	map[count] = NULL;
	return (map);
}
