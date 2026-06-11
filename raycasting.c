/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:34:19 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/07 22:35:18 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	draw_column(t_game *game, int x, t_wall_draw *wall)
{
	t_texture	*tex;

	wall->wall_height = (int)(game->height / wall->perp_wall_dist);
	wall->y_start = (game->height - wall->wall_height) / 2;
	wall->y_end = wall->y_start + wall->wall_height;
	draw_sky_and_floor(game, x, wall->y_start, wall->y_end);
	if (wall->y_start < 0)
		wall->y_start = 0;
	if (wall->y_end >= game->height)
		wall->y_end = game->height - 1;
	tex = select_texture(game, wall->wall_type);
	draw_textured_wall(game, x, wall, tex);
}

void	init_ray_data(t_game *game, int x, t_ray_data *ray, t_wall_draw *wall)
{
	double	camera_x;

	camera_x = 2.0 * x / game->width - 1.0;
	ray->ray_dir_x = game->dir_x + game->plane_x * camera_x;
	ray->ray_dir_y = game->dir_y + game->plane_y * camera_x;
	ray->map_x = (int)game->player_px;
	ray->map_y = (int)game->player_py;
	if (ray->ray_dir_x == 0.0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0.0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
	ray_step_x(ray, game);
	ray_step_y(ray, game);
	ray->side = 0;
	wall->perp_wall_dist = 0;
}

void	calc_wall_intersection(t_ray_data *ray, t_wall_draw *wall, t_game *game)
{
	if (wall->perp_wall_dist < 0.0001)
		wall->perp_wall_dist = 0.0001;
	if (ray->side == 0)
		wall->wall_x = game->player_py + wall->perp_wall_dist * ray->ray_dir_y;
	else
		wall->wall_x = game->player_px + wall->perp_wall_dist * ray->ray_dir_x;
	wall->wall_x -= floor(wall->wall_x);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		wall->wall_x = 1.0 - wall->wall_x;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		wall->wall_x = 1.0 - wall->wall_x;
}

void	cast_column(t_game *game, int x)
{
	t_ray_data	ray;
	t_wall_draw	wall;

	init_ray_data(game, x, &ray, &wall);
	if (!traverse_dda(game, &ray))
		return ;
	if (ray.side == 0)
		wall.perp_wall_dist = ray.side_dist_x - ray.delta_dist_x;
	else
		wall.perp_wall_dist = ray.side_dist_y - ray.delta_dist_y;
	calc_wall_intersection(&ray, &wall, game);
	wall.wall_type = get_wall_type(ray.side, ray.ray_dir_x, ray.ray_dir_y);
	draw_column(game, x, &wall);
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->width)
	{
		cast_column(game, x);
		x++;
	}
}
