/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 08:24:58 by torasolo          #+#    #+#             */
/*   Updated: 2026/04/07 23:15:34 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);

size_t	strlen_gnl(const char *s);

char	*strchr_gnl(const char *s, int c);

size_t	strlcpy_gnl(char *dst, const char *src, size_t size);

void	*calloc_gnl(size_t nmemb, size_t size);

char	*strjoin_gnl(char const *s1, char const *s2);

#endif