/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:35:02 by lleodev           #+#    #+#             */
/*   Updated: 2024/06/21 17:35:04 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_specifier(const char format, va_list ap)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), 0));
	else if (format == 'X')
		return (ft_puthex(va_arg(ap, unsigned int ), 1));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(ap, unsigned int)));
	else if (format == 'p')
		return (ft_putpointer(va_arg(ap, unsigned long long)));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr((va_arg(ap, int))));
	return (0);
}
