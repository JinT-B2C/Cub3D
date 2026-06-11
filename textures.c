/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:36:17 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/06 13:56:37 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

t_texture	*select_texture(t_game *game, char wall_type)
{
	if (wall_type == 'N')
		return (&game->tex_n);
	if (wall_type == 'S')
		return (&game->tex_s);
	if (wall_type == 'W')
		return (&game->tex_w);
	return (&game->tex_e);
}

int	get_texture_pixel(t_texture *tex, int x, int y)
{
	char	*dst;

	if (!tex->addr || x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0x000000);
	dst = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

static t_texture	load_texture(void *mlx, const char *path)
{
	t_texture	tex;

	ft_memset(&tex, 0, sizeof(t_texture));
	tex.img = mlx_xpm_file_to_image(mlx, (char *)path, &tex.width, &tex.height);
	if (!tex.img)
		return (tex);
	tex.addr = mlx_get_data_addr(tex.img, &tex.bits_per_pixel, &tex.line_length,
			&tex.endian);
	return (tex);
}

int	init_textures(t_game *game)
{
	game->tex_n = load_texture(game->mlx, game->conf.tex_n);
	game->tex_s = load_texture(game->mlx, game->conf.tex_s);
	game->tex_w = load_texture(game->mlx, game->conf.tex_w);
	game->tex_e = load_texture(game->mlx, game->conf.tex_e);
	if (!game->tex_n.addr || !game->tex_s.addr || !game->tex_w.addr
		|| !game->tex_e.addr)
		return (0);
	return (1);
}

void	free_textures(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->tex_n.img)
		mlx_destroy_image(game->mlx, game->tex_n.img);
	if (game->tex_s.img)
		mlx_destroy_image(game->mlx, game->tex_s.img);
	if (game->tex_w.img)
		mlx_destroy_image(game->mlx, game->tex_w.img);
	if (game->tex_e.img)
		mlx_destroy_image(game->mlx, game->tex_e.img);
}
