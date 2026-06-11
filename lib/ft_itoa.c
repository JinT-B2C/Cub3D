/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:51:05 by torasolo          #+#    #+#             */
/*   Updated: 2025/03/22 14:56:05 by torasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int	len;

	len = 0;
	if (0 >= n)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*str;

	len = length(n);
	str = malloc(sizeof(char) * len + 1);
	sign = 0;
	nbr = n;
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		sign = 1;
		nbr *= (-1);
	}
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign > 0)
		str[0] = '-';
	return (str);
}
