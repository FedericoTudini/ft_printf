/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:36:34 by ftudini           #+#    #+#             */
/*   Updated: 2021/10/06 17:15:21 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int count_digits_hex(unsigned long int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int count_digits_short(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

unsigned int ft_lenbase(char *base)
{
	int len;
	int j;

	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '+' || base[len] == '-')
			return (1);
		j = 0;
		while (j < len)
		{
			if (base[j] == base[len])
				return (1);
			j++;
		}
		len++;
	}
	if (len == 0 || len == 1)
		return (1);
	return (len);
}

void ft_putnbr_base(unsigned long int nbr, char *base)
{
	unsigned long int nbr_uns;
	unsigned long int len;

	len = ft_lenbase(base);
	if (len == 1)
		return;
	nbr_uns = (unsigned long int)nbr;
	if (nbr_uns >= len)
	{
		ft_putnbr_base(nbr_uns / len, base);
		ft_putnbr_base(nbr_uns % len, base);
	}
	else
	{
		write(1, &base[nbr_uns], 1);
	}
}
