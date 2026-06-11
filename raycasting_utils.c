/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:34:19 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/07 23:26:29 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

char	get_wall_type(int side, double ray_dir_x, double ray_dir_y)
{
	if (side == 0 && ray_dir_x > 0)
		return ('W');
	if (side == 0 && ray_dir_x < 0)
		return ('E');
	if (side == 1 && ray_dir_y > 0)
		return ('N');
	return ('S');
}

static void	step_ray(t_ray_data *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

int	traverse_dda(t_game *game, t_ray_data *ray)
{
	while (1)
	{
		step_ray(ray);
		if (ray->map_x < 0 || ray->map_x >= game->conf.map_width
			|| ray->map_y < 0 || ray->map_y >= game->conf.map_height)
			return (0);
		if (game->conf.map[ray->map_y][ray->map_x] == '1')
			return (1);
	}
	return (0);
}
