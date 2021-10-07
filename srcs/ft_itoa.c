/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftudini <ftudini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:43:07 by ftudini           #+#    #+#             */
/*   Updated: 2021/04/01 17:12:45 by ftudini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_len(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

int		count_digits(int n)
{
	int len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	num;

	len = count_digits(n);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len + 1] = 0;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		num = -n;
		str[0] = '-';
	}
	else
		num = n;
	while (num != 0 && str[len - 1] != '-' && len >= 0 && n != 0)
	{
		str[len-- - 1] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	num_len = ft_len(n, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}


