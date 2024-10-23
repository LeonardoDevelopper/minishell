/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otherput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:33:13 by lleodev           #+#    #+#             */
/*   Updated: 2024/06/21 17:33:15 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, int c)
{
	char	*base;
	int		count;

	count = 0;
	if (c != 0)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, c);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putpointer(unsigned long long ptr)
{
	char	buffer[16];
	char	*hex_digits;
	int		count;
	int		i;

	count = 0;
	if (ptr == 0)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	else
	{
		count += ft_putstr("0x");
		hex_digits = "0123456789abcdef";
		i = 0;
		while (ptr > 0)
		{
			buffer[i++] = hex_digits[ptr % 16];
			ptr /= 16;
		}
		while (i > 0)
			count += ft_putchar(buffer[--i]);
	}
	return (count);
}
