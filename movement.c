/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:35:53 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/07 22:53:39 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	can_move(t_game *game, double x, double y)
{
	int	mx;
	int	my;

	if (x < MARGIN || y < MARGIN)
		return (0);
	mx = (int)(x - MARGIN);
	my = (int)(y - MARGIN);
	if (mx < 0 || my < 0 || mx >= game->conf.map_width
		|| my >= game->conf.map_height || game->conf.map[my][mx] == '1')
		return (0);
	mx = (int)(x + MARGIN);
	if (mx >= game->conf.map_width || game->conf.map[my][mx] == '1')
		return (0);
	mx = (int)(x - MARGIN);
	my = (int)(y + MARGIN);
	if (my >= game->conf.map_height || game->conf.map[my][mx] == '1')
		return (0);
	mx = (int)(x + MARGIN);
	if (mx >= game->conf.map_width || my >= game->conf.map_height
		|| game->conf.map[my][mx] == '1')
		return (0);
	return (1);
}

void	try_move(t_game *game, double dx, double dy)
{
	double	orig_x;
	double	orig_y;

	orig_x = game->player_px;
	orig_y = game->player_py;
	if (can_move(game, orig_x + dx, orig_y))
		game->player_px += dx;
	if (can_move(game, orig_x, orig_y + dy))
		game->player_py += dy;
}

int	accumulate_input(t_game *game, double *out_dx, double *out_dy, double speed)
{
	double	dx;
	double	dy;
	double	len;

	game->dir_x = cos(game->player_angle);
	game->dir_y = sin(game->player_angle);
	dx = 0;
	dy = 0;
	dir_player(game, &dx, &dy);
	if (dx == 0.0 && dy == 0.0)
		return (0);
	len = sqrt(dx * dx + dy * dy);
	*out_dx = dx / len * speed;
	*out_dy = dy / len * speed;
	return (1);
}

void	normalize_angle(t_game *game)
{
	while (game->player_angle < 0)
		game->player_angle += TWO_PI;
	while (game->player_angle >= TWO_PI)
		game->player_angle -= TWO_PI;
}

void	update_player(t_game *game)
{
	const double	speed = 0.04;
	const double	rot_speed = 0.03;
	double			dx;
	double			dy;
	int				moved;

	moved = 0;
	if (accumulate_input(game, &dx, &dy, speed))
	{
		try_move(game, dx, dy);
		moved = 1;
	}
	if (game->rotate_left || game->rotate_right)
	{
		if (game->rotate_left)
			game->player_angle -= rot_speed;
		if (game->rotate_right)
			game->player_angle += rot_speed;
		normalize_angle(game);
		update_camera_vectors(game);
		moved = 1;
	}
	if (moved)
		game->dirty = 1;
}
