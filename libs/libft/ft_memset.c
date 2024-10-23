/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:49:53 by lleodev           #+#    #+#             */
/*   Updated: 2024/05/16 17:03:49 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*start;

	start = (char *)s;
	i = 0;
	while (i < n)
	{
		*start = (char)c;
		start++;
		i++;
	}
	return (s);
}
