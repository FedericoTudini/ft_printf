/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:09:11 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/23 12:52:08 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_width(char *format, t_flags *flags, va_list ap, int j)
{
	int w;

	w = 0;
	if (!('0' <= format[flags->i + j] && format[flags->i + j] <= '9') || format[flags->i + j] == '*')
		return (0);
	while ('0' <= format[flags->i + j] && format[flags->i + j] <= '9')
	{
		w *= 10;
		w += format[flags->i + j++] - '0';
	}
	if (format[flags->i + j] == '*')
	{
		//Se la width già esiste allora errore
		if (w != 0)
			return (-1);
		w = va_arg(ap, int);
	}
	flags->width = w;
	flags->i += j;
	return (1);
}