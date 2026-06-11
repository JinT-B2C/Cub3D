/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:42:22 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/07 23:29:32 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	ray_step_x(t_ray_data *ray, t_game *game)
{
	if (ray->ray_dir_x < 0.0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player_px - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player_px)
			* ray->delta_dist_x;
	}
}

void	ray_step_y(t_ray_data *ray, t_game *game)
{
	if (ray->ray_dir_y < 0.0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player_py - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player_py)
			* ray->delta_dist_y;
	}
}
