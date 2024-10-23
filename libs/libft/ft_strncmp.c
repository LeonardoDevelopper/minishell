/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:05:27 by lleodev           #+#    #+#             */
/*   Updated: 2024/05/18 19:39:02 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if ((*s1 - *s2) != 0)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0' || *s2 == '\0')
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}
