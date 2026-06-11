/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:35:18 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/11 03:51:10 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move_forward = 1;
	else if (keycode == KEY_S)
		game->move_backward = 1;
	else if (keycode == KEY_A)
		game->move_left = 1;
	else if (keycode == KEY_D)
		game->move_right = 1;
	else if (keycode == KEY_LEFT)
		game->rotate_left = 1;
	else if (keycode == KEY_RIGHT)
		game->rotate_right = 1;
	else if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->move_forward = 0;
	else if (keycode == KEY_S)
		game->move_backward = 0;
	else if (keycode == KEY_A)
		game->move_left = 0;
	else if (keycode == KEY_D)
		game->move_right = 0;
	else if (keycode == KEY_LEFT)
		game->rotate_left = 0;
	else if (keycode == KEY_RIGHT)
		game->rotate_right = 0;
	return (0);
}

int	close_window(t_game *game)
{
	game_cleanup(game);
	exit(0);
	return (0);
}
