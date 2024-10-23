/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:42:00 by lleodev           #+#    #+#             */
/*   Updated: 2024/05/18 19:44:15 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*it_s;
	int				i;

	i = 0;
	it_s = (unsigned char *)s;
	while (i < (int)n)
	{
		if (it_s[i] == (unsigned char)c)
			return (&it_s[i]);
		i++;
	}
	return (NULL);
}
