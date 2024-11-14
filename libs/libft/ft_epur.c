/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:09:41 by aborges           #+#    #+#             */
/*   Updated: 2024/11/13 13:09:50 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	count_epur_size(char *str)
{
	int	i;
	int	size;
	int	count;

	i = 0;
	size = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		while (str[i] && !is_space(str[i]))
		{
			size++;
			i++;
			count = 1;
		}
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && count)
			size++;
	}
	return (size);
}

void	fill_epur_str(char *str, char *result)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		while (str[i] && !is_space(str[i]))
		{
			result[j++] = str[i++];
			count = 1;
		}
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && count)
		{
			result[j++] = ' ';
			count = 0;
		}
	}
	result[j] = '\0';
}

char	*epur_str(char *str)
{
	char	*result;
	int		size;

	size = count_epur_size(str);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	fill_epur_str(str, result);
	return (result);
}
