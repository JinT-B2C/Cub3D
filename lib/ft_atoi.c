/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frazakar <frazakar@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:46:25 by torasolo          #+#    #+#             */
/*   Updated: 2026/06/06 13:56:58 by frazakar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;
	char	*cast;

	i = 0;
	res = 0;
	sign = 1;
	cast = ((char *)str);
	while ((cast[i] == ' ') || ((cast[i] >= 9) && (cast[i] <= 13)))
		i++;
	if (cast[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (cast[i] == '+')
		i++;
	while (cast[i] && cast[i] >= '0' && cast[i] <= '9')
	{
		if (cast[i] >= '0' && cast[i] <= '9')
			res = res * 10 + cast[i] - '0';
		i++;
	}
	return (res * sign);
}
