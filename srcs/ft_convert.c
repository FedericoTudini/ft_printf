/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:21:05 by ftudini           #+#    #+#             */
/*   Updated: 2021/10/06 18:56:27 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_handle_char(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->ret++;
}

void ft_handle_str(char *str, t_flags *flags)
{
	int len;

	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	flags->ret += len;
}

void ft_handle_int(int n, t_flags *flags)
{
	char *str;

	str = ft_itoa(n);
	ft_putstr_fd(str, 1);
	flags->ret += ft_strlen(str);
	free(str);
}

void ft_handle_unsi(unsigned int unsi, t_flags *flags)
{
	char *str;

	str = ft_itoa(unsi);
	ft_putstr_fd(str, 1);
	flags->ret += ft_strlen(str);
	free(str);
}

void ft_handle_hexa_low(unsigned int n, t_flags *flags)
{
	ft_putnbr_base(n, "0123456789abcdef");
	flags->ret += count_digits_hex(n);
}

void ft_handle_hexa_up(unsigned int n, t_flags *flags)
{
	ft_putnbr_base(n, "0123456789ABCDEF");
	flags->ret += count_digits_hex(n);
}

void ft_handle_pointer(unsigned long int n, t_flags *flags)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(n, "0123456789abcdef");
	flags->ret += count_digits_hex(n);
}

void ft_parsing(t_flags *flags, char *format, va_list ap)
{
	flags->i++;
	if (format[flags->i] == 'c')
		ft_handle_char(va_arg(ap, int), flags);
	if (format[flags->i] == 's')
		ft_handle_str(va_arg(ap, char *), flags);
	if (format[flags->i] == 'd' || format[flags->i] == 'i')
		ft_handle_int(va_arg(ap, int), flags);
	if (format[flags->i] == 'x')
		ft_handle_hexa_low(va_arg(ap, unsigned int), flags);
	if (format[flags->i] == 'X')
		ft_handle_hexa_up(va_arg(ap, unsigned int), flags);
	if (format[flags->i] == 'p')
		ft_handle_pointer(va_arg(ap, unsigned long int), flags);
	if (format[flags->i] == '%')
		ft_putchar_fd(format[flags->i++], 1);
}