/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:35:56 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/11 00:02:23 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	is_texture_id(const char *line)
{
	if (!line || !*line)
		return (0);
	return (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0);
}

int	is_color_id(const char *line)
{
	if (!line || !*line)
		return (0);
	return (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0);
}

int	looks_like_map(const char *line)
{
	if (!line || !*line)
		return (0);
	while (*line)
	{
		if (*line == '0' || *line == '1' || *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W')
			return (1);
		line++;
	}
	return (0);
}

int	all_header_set(t_conf *conf)
{
	return (conf->tex_n && conf->tex_s && conf->tex_w && conf->tex_e
		&& conf->floor_set && conf->sky_set);
}

char	*skip_spaces(const char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return ((char *)s);
}
