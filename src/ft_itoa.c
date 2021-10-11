/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:43:07 by ftudini           #+#    #+#             */
/*   Updated: 2021/10/11 18:12:25 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n;
	len = aux_len(n);
	num = aux_num(num);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	*(str + len--) = '\0';
	while (num > 0)
	{
		*(str + len--) = num % 10 + '0';
		num /= 10;
	}
	if (len == 0 && str[1] == '\0')
		*(str + len) = '0';
	else if (len == 0 && str[1] != '\0')
		*(str + len) = '-';
	return (str);
}

size_t	aux_len(int n)
{
	size_t	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	aux_num(long num)
{
	if (num > 0)
		return (num);
	return (-num);
}
