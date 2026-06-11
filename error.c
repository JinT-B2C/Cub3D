/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 02:20:05 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/06 13:56:12 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

void	print_error(const char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
	exit(1);
}

void	game_error(const char *message, t_game *game)
{
	game_cleanup(game);
	if (message)
		ft_putendl_fd(message, 2);
	exit(1);
}

void	game_cleanup(t_game *game)
{
	free_textures(game);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_config(&game->conf);
}
