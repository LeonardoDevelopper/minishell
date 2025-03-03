/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:37:48 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/09 12:23:39 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_mat_char(char **mat)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			size++;
			j++;
		}
		size += 1;
		i++;
	}
	return (size);
}

char	*ft_strjoin_matrix(char **mat, char c)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	*new_str;

	i = 0;
	k = 0;
	size = count_mat_char(mat);
	new_str = (char *)malloc(sizeof(char ) * (size + 1));
	if (!new_str)
		return (NULL);
	new_str[size] = '\0';
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
			new_str[k++] = mat[i][j++];
		new_str[k++] = c;
		i++;
	}
	return (new_str);
}

int	count_rows(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

int	ft_strcpy_custom(int begin, char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = begin;
	if (!dst || !src)
		return (0);
	while (src[i])
		dst[j++] = src[i++];
	return (i);
}
