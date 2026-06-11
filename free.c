/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:35:23 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/06 13:56:17 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_config(t_conf *conf)
{
	if (!conf)
		return ;
	if (conf->tex_n)
		free(conf->tex_n);
	if (conf->tex_s)
		free(conf->tex_s);
	if (conf->tex_w)
		free(conf->tex_w);
	if (conf->tex_e)
		free(conf->tex_e);
	if (conf->map)
		free_map(conf->map);
	conf->tex_n = NULL;
	conf->tex_s = NULL;
	conf->tex_w = NULL;
	conf->tex_e = NULL;
	conf->map = NULL;
}
