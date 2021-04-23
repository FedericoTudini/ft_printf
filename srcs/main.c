/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:04:48 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/23 12:33:15 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main(int argc, char **argv)
{
	
	char c = 'd';
	char b = 'e';
	int n = -3376587;
	int un = -12233;
	char *str = "Johnnie B. Goode";
	ft_printf("interi -> %d, %i, - stringa -> %s, carattere -> %c %c. \n", n, un, str, c, b);
	ft_printf("Digits hex: %d - hex: %x\n", count_digits_short(n), n);
	if (argc != 0)
	{
		ft_printf("%s \n",argv[0]);
	}
}