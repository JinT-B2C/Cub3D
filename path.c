/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:36:00 by frazakar          #+#    #+#             */
/*   Updated: 2026/06/11 03:41:31 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

int	check_path(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len <= 3 || ft_strncmp(path + len - 4, ".cub", 4) != 0)
		return (0);
	if (ft_strncmp(".cub", path, ft_strlen(".cub")) == 0)
		return (0);
	if (path[len - 4] != '.' || path[len - 3] != 'c' || path[len - 2] != 'u'
		|| path[len - 1] != 'b')
		return (0);
	else if (path[len - 4] == '.' && path[len - 3] == 'c' && path[len
			- 2] == 'u' && path[len - 1] == 'b' && path[len - 5] == '/')
		return (0);
	return (1);
}

char	*strip_nl(char *s)
{
	int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
	return (s);
}

int	is_line_empty(const char *s)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n' && *s != '\r')
			return (0);
		s++;
	}
	return (1);
}

void	free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}
