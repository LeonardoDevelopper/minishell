/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:33:56 by lleodev           #+#    #+#             */
/*   Updated: 2024/05/18 19:56:25 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little == NULL || little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < n)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i + j < n)
			{
				if (little[j + 1] == '\0')
					return ((char *)big + i);
				j++;
			}
			j = 0;
		}	
		i++;
	}
	return (NULL);
}
