/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:47:18 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/23 12:50:55 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_atoi(const char *nptr)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	while (*nptr == '\n' || *nptr == '\t' || *nptr == '\v' 
		|| *nptr == '\r' || *nptr == '\f' || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res *= 10;
		res += (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}