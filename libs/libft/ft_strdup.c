/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:18:32 by lleodev           #+#    #+#             */
/*   Updated: 2024/09/14 14:43:38 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	char	*start;

	if (s == NULL)
		return (NULL);
	cpy = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	start = cpy;
	while (*s != '\0' || *s != '\n')
	{
		*cpy = *s;
		cpy++;
		s++;
	}
	*cpy = '\0';
	return (start);
}
