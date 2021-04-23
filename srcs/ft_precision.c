/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:09:52 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/23 12:51:46 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_precision(char *format, t_flags *flags, va_list ap)
{
	int j;
	int p;
	
	j = 0;
	p = 0;
	if (format[flags->i + j] != '.')
		return (0);
	flags->i++;
	if (format[flags->i + j] == '*')
	{
		flags->precision = va_arg(ap, int);
		return (1);
	}
	while ('0' <= format[flags->i + j] && format[flags->i + j] <= '9')
	{
		p *= 10;
		p += format[flags->i + j++] - '0';
	}
	flags->precision = p;
	return (1);
}