/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:11:44 by aborges           #+#    #+#             */
/*   Updated: 2025/01/08 13:11:47 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_rowss(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
	        if (str[i] == '<' || str[i] == '>' || str[i] == '|')
			len++;
		i++;
	}
	return (len);
}

int	ft_strlenn(char *str)
{
	int	len;

	len = 0;
	while (str[len] && !(str[len] == '<' || str[len] == '>' || str[len] == '|'))
		len++;
	return (len);
}

char	**ft_split_args(char *str)
{
	int	i;
	int	j;
	int	len1;
	int	len2;
	char	**res;

	i = 0;
	len1 = count_rowss(str) + 1;
	res = (char **)malloc(sizeof(char *) * (len1 + 1));
	res[len1] = NULL;
	while (i < len1)
	{
		len2 = ft_strlenn(str);
		res[i] = (char *)malloc(sizeof(char ) * (len2 + 1));
		j = 0;
		while (*str && (*str == '<' || *str == '>' || *str == '|'))
			str++;
		while (*str && !(*str == '<' || *str == '>' || *str == '|'))
			res[i][j++] = *str++;
		res[i][j] = '\0';
		i++;
	}
	return (res);
}
