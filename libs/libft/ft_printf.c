/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:33:26 by lleodev           #+#    #+#             */
/*   Updated: 2024/06/21 17:33:28 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	if (format == NULL)
		return (-1);
	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format [i + 1] != '\0')
		{
			count += ft_type_specifier(format[i + 1], ap);
			i++;
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
