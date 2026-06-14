/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:35:32 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/14 17:55:07 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	update_camera_vectors(t_game *game)
{
	game->dir_x = cos(game->player_angle);
	game->dir_y = sin(game->player_angle);
	game->plane_x = -game->dir_y * FOV_FACTOR;
	game->plane_y = game->dir_x * FOV_FACTOR;
}

static void	set_player_angle(t_game *game)
{
	if (game->conf.player_or == 'N')
		game->player_angle = 3.0 * PI / 2.0;
	else if (game->conf.player_or == 'S')
		game->player_angle = PI / 2.0;
	else if (game->conf.player_or == 'E')
		game->player_angle = 0.0;
	else if (game->conf.player_or == 'W')
		game->player_angle = PI;
	update_camera_vectors(game);
}

static void	precompute_colors(t_game *game)
{
	game->ceil_color = (game->conf.sky.r << 16)
		| (game->conf.sky.g << 8) | game->conf.sky.b;
	game->floor_color = (game->conf.floor.r << 16)
		| (game->conf.floor.g << 8) | game->conf.floor.b;
}

static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		game_error("Error: Failed to init mlx", game);
	game->width = DEFAULT_WIDTH;
	game->height = DEFAULT_HEIGHT;
	game->win = mlx_new_window(game->mlx, game->width, game->height,
			"Ping_Pong");
	if (!game->win)
		game_error("Error: Failed to create window", game);
	game->img.img = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->img.img)
		game_error("Error: Failed to create image buffer", game);
}

int	init_game(t_game *game, const char *map_path)
{
	if (!game || !map_path)
		return (0);
	if (!parse_cub_file(map_path, &game->conf))
		game_error(NULL, game);
	init_mlx(game);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	if (!init_textures(game))
		game_error("Error: Failed to load textures", game);
	game->player_px = game->conf.player_x + 0.5;
	game->player_py = game->conf.player_y + 0.5;
	set_player_angle(game);
	precompute_colors(game);
	game->dirty = 1;
	return (1);
}
