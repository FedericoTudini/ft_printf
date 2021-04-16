/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:04:48 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/03 16:50:27 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main(int argc, char **argv)
{
	char c = 'd';
	char b = 'e';
	char *p;
	int n = -3376587;
	int un = -12233;
	int ret = 0;
	char *str = "Johnnie B. Goode";
	ft_printf("interi -> %d, %i, - stringa -> %s, carattere -> %c %c. \n", n, un, str, c, b);
	ft_printf("Digits hex: %d - hex: %x\n", count_digits_short(n), n);
	ft_printf("pointer -> %p\n", p);
	printf("pointer -> %p percent -> %%\n", p);
}