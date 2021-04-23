/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:44:10 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/23 12:08:51 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_normal(t_flags *flags, char *format)
{
	int		len;

	len = 0;
	while (format[flags->i + len] && format[flags->i + len] != 37)
	{
		write(1, &(format[flags->i + len]), 1);
		len++;
	}
	flags->i += len - 1;
	flags->ret += len;
}

void	init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = 0;
	flags->zero = 0;
	flags->minus = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_flags			flags;

	init_flags(&flags);
	flags.i = 0;
	flags.ret = 0;
	va_start(ap, format);
	while(format[flags.i])
	{
		if (format[flags.i] == 37)
		{
			if (format[flags.i + 1] == '\0')
				break;
			if (check_format(format[flags.i + 1]) || check_flag(format[flags.i + 1]))
				if (ft_parsing(&flags, (char*)format, ap) < 0)
				{
					ft_putchar_fd('%', 1);
					print_normal(&flags, (char*)format);
				}
		}
		else
			print_normal(&flags, (char*)format);
		flags.i++;
	}
	va_end(ap);
	return (flags.ret);
}