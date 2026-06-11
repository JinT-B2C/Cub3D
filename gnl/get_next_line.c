/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:23:31 by torasolo          #+#    #+#             */
/*   Updated: 2026/04/07 23:15:26 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_gnl(char *buff, char *buf)
{
	char	*tmp;

	tmp = strjoin_gnl(buff, buf);
	free(buff);
	return (tmp);
}

char	*stock_next_line(char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!buf || !*buf)
		return (free(buf), NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	line = calloc_gnl(strlen_gnl(buf) - i, sizeof(char));
	if (!line)
		return (free(buf), NULL);
	j = -1;
	while (buf[++i])
		line[++j] = buf[i];
	free(buf);
	return (line);
}

char	*stock_new_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf || !*buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = calloc_gnl(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_fd(int fd, char *readed)
{
	char	*buf;
	int		size;

	if (!readed)
		readed = calloc_gnl(1, 1);
	buf = calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (free(readed), NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
			return (free(buf), free(readed), NULL);
		buf[size] = 0;
		readed = free_gnl(readed, buf);
		if (strchr_gnl(buf, '\n'))
			break ;
	}
	free(buf);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*buf[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buf[fd]);
		buf[fd] = NULL;
		return (NULL);
	}
	buf[fd] = read_fd(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = stock_new_line(buf[fd]);
	buf[fd] = stock_next_line(buf[fd]);
	if (buf[fd] && *buf == 0)
	{
		free(buf[fd]);
		buf[fd] = NULL;
	}
	return (line);
}
