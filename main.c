/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:35:41 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/06 13:56:20 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		print_error("Error\nUsage: ./cub3D <map.cub>");
	ft_memset(&game, 0, sizeof(t_game));
	game.width = DEFAULT_WIDTH;
	game.height = DEFAULT_HEIGHT;
	init_game(&game, av[1]);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, render, &game);
	mlx_loop(game.mlx);
	game_cleanup(&game);
	return (0);
}
