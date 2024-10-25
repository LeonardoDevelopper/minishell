/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:13:35 by lleodev           #+#    #+#             */
/*   Updated: 2024/05/21 19:44:29 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*start;
	size_t	total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *) malloc((total_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	start = result;
	while (*s1 != '\0')
	{
		*result = *s1;
		result++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*result = *s2;
		result++;
		s2++;
	}
	*result = '\0';
	return (start);
}
