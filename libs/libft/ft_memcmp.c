/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:11:12 by lleodev           #+#    #+#             */
/*   Updated: 2024/05/18 19:41:49 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	int				result;

	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while ((int)n > 0)
	{
		result = (*ptr_s1 - *ptr_s2);
		if (result != 0)
			return (result);
		ptr_s1++;
		ptr_s2++;
		n--;
	}
	return (0);
}
