/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 22:48:49 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/08 00:38:15 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	dir_player(t_game *game, double *dx, double *dy)
{
	if (game->move_forward)
	{
		*dx += game->dir_x;
		*dy += game->dir_y;
	}
	if (game->move_backward)
	{
		*dx -= game->dir_x;
		*dy -= game->dir_y;
	}
	if (game->move_left)
	{
		*dx -= game->dir_y;
		*dy += game->dir_x;
	}
	if (game->move_right)
	{
		*dx += game->dir_y;
		*dy -= game->dir_x;
	}
}
