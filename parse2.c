/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:01:09 by torasolo          #+#    #+#             */
/*   Updated: 2026/06/14 17:48:09 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "lib/libft.h"
#include <stdio.h>

static int	set_it(char **s, const char *line)
{
	if (*s)
		return (0);
	*s = ft_strdup(skip_spaces(line));
	return (1);
}

int	try_set_texture(const char *line, t_conf *conf)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (set_it(&conf->tex_n, line + 2));
	if (ft_strncmp(line, "SO", 2) == 0)
		return (set_it(&conf->tex_s, line + 2));
	if (ft_strncmp(line, "WE", 2) == 0)
		return (set_it(&conf->tex_w, line + 2));
	if (ft_strncmp(line, "EA", 2) == 0)
		return (set_it(&conf->tex_e, line + 2));
	return (0);
}

int	parse_rgb_values(char **rgb, t_conf *conf, char c)
{
	t_rgb	*color;

	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (0);
	if (c == 'F')
		color = &conf->floor;
	else
		color = &conf->sky;
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	return (color->r >= 0 && color->r <= 255 && color->g >= 0 && color->g <= 255
		&& color->b >= 0 && color->b <= 255);
}

static int	check_rgb_format(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	return (1);
}

void	parse_color(const char *line, t_conf *conf)
{
	char		**rgb;
	const char	*values;
	int			i;

	values = skip_spaces(line + 1);
	rgb = ft_split(values, ',');
	if (!rgb)
		return ;
	if (!check_rgb_format(rgb[2]))
	{
		free_lines(rgb);
		return ;
	}
	if (parse_rgb_values(rgb, conf, line[0]))
	{
		if (line[0] == 'F')
			conf->floor_set = 1;
		else if (line[0] == 'C')
			conf->sky_set = 1;
	}
	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
}
