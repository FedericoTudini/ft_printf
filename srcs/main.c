/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:04:48 by ftudini           #+#    #+#             */
/*   Updated: 2021/10/06 18:48:42 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main(int argc, char **argv)
{
	char c = 'd';
	char b = 'e';
	int n = 3376587;
	int un = 12233;
	int ret = 0;
	unsigned int unsi = 214748569;
	char *str = "di";
	ret = ft_printf("interi -> %d, %i, - stringa -> %s, carattere -> %c %c. \n", n, un, str, c, b);
	ft_printf("ret = %d\n", ret);
	ret = printf("interi -> %d, %i, - stringa -> %s, carattere -> %c %c. \n", n, un, str, c, b);
	ft_printf("ret = %d\n", ret);
	ret = ft_printf("Digits hex: %d- hex: %x\n", count_digits_short(n), n);
	ft_printf("ret = %d\n", ret);
	ret = printf("Digits hex: %d- hex: %x\n", count_digits_short(n), n);
	ft_printf("ret = %d\n", ret);
	printf("%u\n", unsi);
	ft_printf("%u\n", unsi);
}