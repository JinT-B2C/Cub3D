/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 03:34:54 by torasolo          #+#    #+#             */
/*   Updated: 2026/06/14 17:49:32 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	init_config(t_conf *conf)
{
	conf->tex_n = NULL;
	conf->tex_s = NULL;
	conf->tex_w = NULL;
	conf->tex_e = NULL;
	conf->floor.r = -1;
	conf->floor.g = -1;
	conf->floor.b = -1;
	conf->sky.r = -1;
	conf->sky.g = -1;
	conf->sky.b = -1;
	conf->floor_set = 0;
	conf->sky_set = 0;
	conf->map = NULL;
	conf->map_width = 0;
	conf->map_height = 0;
	conf->player_x = -1;
	conf->player_y = -1;
	conf->player_or = '\0';
}

int	is_duplicate(const char *line, t_conf *conf)
{
	if (ft_strncmp(line, "NO", 2) == 0 && conf->tex_n)
		return (1);
	if (ft_strncmp(line, "SO", 2) == 0 && conf->tex_s)
		return (1);
	if (ft_strncmp(line, "WE", 2) == 0 && conf->tex_w)
		return (1);
	if (ft_strncmp(line, "EA", 2) == 0 && conf->tex_e)
		return (1);
	if (line[0] == 'F' && conf->floor_set)
		return (1);
	if (line[0] == 'C' && conf->sky_set)
		return (1);
	return (0);
}
