/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:44:10 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/02 21:45:26 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'n' || c == 'X' || c == '%'
	|| c == '-' || c == ' ' || c == '.' || c == '*' || 
	(c >= '0' && c <= '9'))
		return (1);
	return(0);
}

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
	flags->i = 0;
	flags->ret = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->dot = 0;
	flags->times = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_flags			flags;
	unsigned int	ret;

	init_flags(&flags);

	va_start(ap, format);
	while(format[flags.i])
	{
		if (format[flags.i] == 37)
		{
			if (format[flags.i + 1] == '\0')
				break;
			if (check_char(format[flags.i + 1]))
				ft_parsing(&flags, (char*)format, ap);	
		}
		else
			print_normal(&flags, (char*)format);
		flags.i++;
	}
	va_end(ap);
	ret = flags.ret;
	return (ret);
}