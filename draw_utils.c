/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:52:03 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/08 00:37:26 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	draw_sky_and_floor(t_game *game, int x, int y_start, int y_end)
{
	int	coord[2];

	coord[0] = x;
	coord[1] = 0;
	while (coord[1] < y_start && coord[1] < game->height)
	{
		pixel_put(&game->img, coord, game->ceil_color, game);
		coord[1]++;
	}
	coord[1] = y_end;
	while (coord[1] < game->height)
	{
		pixel_put(&game->img, coord, game->floor_color, game);
		coord[1]++;
	}
}

int	text_affect(int i, t_texture *tex, int text_coord)
{
	if (text_coord < 0)
		text_coord = 0;
	if (i == 0 && text_coord >= tex->width)
		text_coord = tex->width - 1;
	else if (i == 1 && text_coord >= tex->height)
		text_coord = tex->height - 1;
	return (text_coord);
}

void	draw_textured_wall(t_game *game, int x, t_wall_draw *wall,
		t_texture *tex)
{
	double	step;
	double	tex_pos;
	int		text[2];
	int		coord[2];
	int		pixel;

	text[0] = (int)(wall->wall_x * (double)tex->width);
	text[0] = text_affect(0, tex, text[0]);
	step = (double)tex->height / wall->wall_height;
	tex_pos = ((double)wall->y_start - (double)(game->height
				- wall->wall_height) / 2.0) * step;
	coord[0] = x;
	coord[1] = wall->y_start;
	while (coord[1] <= wall->y_end)
	{
		text[1] = (int)tex_pos;
		text[1] = text_affect(1, tex, text[1]);
		tex_pos += step;
		pixel = get_texture_pixel(tex, text[0], text[1]);
		pixel_put(&game->img, coord, pixel, game);
		coord[1]++;
	}
}
