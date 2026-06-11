/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:35:36 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/11 03:38:13 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static int	err_exit(char **lines, t_conf *conf, const char *msg)
{
	ft_putendl_fd(msg, 2);
	free_lines(lines);
	if (conf)
		free_config(conf);
	return (0);
}

int	valid_map_chars(const char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != ' ' && *line != 'N'
			&& *line != 'S' && *line != 'E' && *line != 'W' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

static int	handle_header_line(char *line, t_conf *conf, int *map_start, int i)
{
	if (is_line_empty(line))
		return (1);
	if (is_texture_id(line) || is_color_id(line))
	{
		if (is_duplicate(line, conf))
			return (0);
		if (is_texture_id(line))
		{
			if (!try_set_texture(line, conf))
				return (0);
		}
		else
			parse_color(line, conf);
		return (1);
	}
	if (looks_like_map(line))
	{
		if (!all_header_set(conf))
			return (0);
		*map_start = i;
		return (2);
	}
	return (0);
}

static int	process_lines(char **lines, t_conf *conf, int *map_start)
{
	int		i;
	int		ret;
	char	*line;

	i = 0;
	while (lines[i])
	{
		line = strip_nl(lines[i]);
		if (*map_start == -1)
		{
			ret = handle_header_line(line, conf, map_start, i);
			if (ret == 0)
				return (0);
		}
		else
		{
			if (!is_line_empty(line) && !valid_map_chars(line))
				return (-1);
		}
		i++;
	}
	return (1);
}

int	parse_cub_file(const char *path, t_conf *conf)
{
	char	**lines;
	int		map_start;
	int		res;

	if (!path || !conf || !check_path((char *)path))
		return (err_exit(NULL, NULL, "Invalid or unreadable file path"));
	init_config(conf);
	lines = read_map(path);
	if (!lines)
		return (err_exit(NULL, conf, "Failed to read file"));
	map_start = -1;
	res = process_lines(lines, conf, &map_start);
	if (res == 0)
		return (err_exit(lines, conf,
				"Invalid header: duplicate,unknown id, or incomplete"));
	if (res == -1)
		return (err_exit(lines, conf, "Invalid content after map start"));
	if (map_start == -1)
		return (err_exit(lines, conf, "No map found in file"));
	if (!build_map(lines, conf, map_start))
		return (err_exit(lines, conf, "Failed to build map"));
	if (!validate_map(conf))
		return (err_exit(lines, conf,
				"Map invalid:not closed, no player, or bad character"));
	return (free_lines(lines), 1);
}
