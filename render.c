/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:36:11 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/07 23:25:45 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	pixel_put(t_img *img, int coord[2], int color, t_game *game)
{
	char	*dst;

	if (coord[0] < 0 || coord[0] >= game->width || coord[1] < 0
		|| coord[1] >= game->height)
		return ;
	dst = img->addr + (coord[1] * img->line_length + coord[0]
			* (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render(t_game *game)
{
	update_player(game);
	if (!game->dirty)
		return (0);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	game->dirty = 0;
	return (0);
}
