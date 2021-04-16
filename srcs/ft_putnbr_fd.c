/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:29:31 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/01 16:56:59 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr_uns;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr_uns = (unsigned int)(-1 * n);
	}
	else
	{
		nbr_uns = (unsigned int)n;
	}
	if (nbr_uns >= 10)
	{
		ft_putnbr_fd(nbr_uns / 10, fd);
		ft_putnbr_fd(nbr_uns % 10, fd);
	}
	else
	{
		ft_putchar_fd(nbr_uns + '0', fd);
	}
}
