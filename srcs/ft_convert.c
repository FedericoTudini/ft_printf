/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:21:05 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/23 12:34:43 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_char(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->ret++;
}

void	ft_handle_str(char *str, t_flags *flags)
{
	int len;

	len = 0;
	ft_putstr_fd(str, 1);
	flags->ret += len;
}

void	ft_handle_int(int n, t_flags *flags)
{
	char *str;

	str = ft_itoa(n);
	ft_putstr_fd(str, 1);
	flags->ret += ft_strlen(str);
	free(str);
}

void	ft_handle_hexa_low(unsigned int n, t_flags *flags)
{
	ft_putnbr_base(n, "0123456789abcdef");
	flags->ret += count_digits_hex(n);
}

void	ft_handle_hexa_up(unsigned int n, t_flags *flags)
{
	ft_putnbr_base(n, "0123456789ABCDEF");
	flags->ret += count_digits_hex(n);
}

void	ft_handle_pointer(unsigned long int n, t_flags *flags)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(n, "0123456789abcdef");
	flags->ret += count_digits_hex(n);
}

int		ft_handle_flags(char *format, t_flags *flags, va_list ap)
{
	//aumento j cosi i rimane al carattere successivo al 
	//segno percentuale, in caso di errore nella specifica del formato
	//printo normalmente i caratteri della specifica errata
	int j;

	j = 0;
	//allineamento a sinistra
	if (format[flags->i + j++] == '-')
		flags->minus = 1;
	//uso un while per accertarmi che gli zeri ripetuti vengano intesi come uno solo
	//NB GLI ZERI RIPETUTI NON VANNO PRINTATI
	while (format[flags->i + j++] == '0')
		if (flags->zero == 0)
			flags->zero = 1;
	//se inserisco sia la flag zero che quella meno, prevale la flag meno
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (ft_width(format, flags, ap, j) < 0)
		return (-1);
	if (ft_precision(format, flags, ap) < 0)
		return (-1);
	return (1);
}

int		ft_parsing(t_flags *flags, char *format, va_list ap)
{
	flags->i++;
	//se non è un placeholder
	if (!(check_format(format[flags->i])))
	{
		//controlla che non sia nemmeno una flag
		//se non è un carattere valido allora mando -1 alla funzione superiore che stampa normalmente
		if (!(check_flag(format[flags->i])))
			return (-1);
		//chiama la funzione che analizza i flag, la width, la precision
		//se la funzione ritorna un numero negativo allora qualcosa è andato storto 
		//e lo comunico alla funzione root che sapendo dell'errore stamperà i caratteri normalmente
		if (ft_handle_flags(format, flags, ap) < 0)
			return (-1);
	}
	//controllo il carattere della specifica del formato e da lì capisco
	//quale funzione chiamare, una per tipo
	if (format[flags->i] == 'c')
		ft_handle_char(va_arg(ap, int), flags);
	else if (format[flags->i] == 's')
		ft_handle_str(va_arg(ap, char*), flags);
	else if (format[flags->i] == 'd' || format[flags->i] == 'i')
		ft_handle_int(va_arg(ap, int), flags);
	else if (format[flags->i] == 'x')
		ft_handle_hexa_low(va_arg(ap, unsigned int), flags);
	else if (format[flags->i] == 'X')
		ft_handle_hexa_up(va_arg(ap, unsigned int), flags);
	else if (format[flags->i] == 'p')
		ft_handle_pointer(va_arg(ap, unsigned long int), flags);
	else if (format[flags->i] == '%')
		ft_putchar_fd(format[flags->i++], 1);
	//reset flags
	init_flags(flags);
	return (0);
}