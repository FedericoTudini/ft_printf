/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:47:49 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/23 12:52:28 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>
# include <stdio.h>

typedef struct s_flags {
	int width;
	int precision;
	unsigned int i;
	unsigned int ret;
	int zero;
	int minus;
} t_flags;

int				ft_printf(const char *format, ...);
int				check_format(char c);
int				check_flag(char c);
void			print_normal(t_flags *flags, char *format);
void			init_flags(t_flags *flags);
void			ft_handle_char(char c, t_flags *flags);
int				ft_parsing(t_flags *flags, char *format, va_list ap);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_strlen(const char *str);
void			ft_putchar_fd(char c, int fd);
int				count_digits(int n);
char			*ft_itoa(int n);
void			ft_putnbr_base(unsigned long int nbr, char *base);
unsigned int	ft_lenbase(char *base);
int				count_digits_hex(unsigned long int n);
int				count_digits_short(unsigned int n);
void			ft_handle_hexa_low(unsigned int n, t_flags *flags);
void			ft_handle_hexa_up(unsigned int n, t_flags *flags);
int				ft_precision(char *format, t_flags *flags, va_list ap);
int				ft_width(char *format, t_flags *flags, va_list ap, int j);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);

#endif
