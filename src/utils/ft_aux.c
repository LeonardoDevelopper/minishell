/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:48:06 by aborges           #+#    #+#             */
/*   Updated: 2024/10/23 12:26:54 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_toupper_str(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (str);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (0);
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] != '\0' || str2[i] != '\0')
		return (0);
	return (1);
}

int	get_start_index(char *path)
{
	int	i;

	i = 0;
	if (!path)
		return (-1);
	while (path[i] && path[i] != '=')
		i++;
	if (path[i] == '=')
		i++;
	return (i);
}

char	**ft_split_path(char *path)
{
	static char	mat[250][250];
	static char	*result[250];
	int			i;
	int			j;
	int			k;

	i = get_start_index(path);
	j = 0;
	if (i == -1)
		return (NULL);
	ft_memset(mat, 0, sizeof(mat));
	while (path[i])
	{
		k = 0;
		while (path[i] && path[i] != ':')
			mat[j][k++] = path[i++];
		mat[j][k] = '/';
		result[j++] = mat[j];
		if (path[i])
			i++;
	}
	result[j] = NULL;
	return (result);
}

void	fill_str(char *str)
{
	str[0] = '~';
	str[1] = '!';
	str[2] = '@';
	str[3] = '#';
	str[4] = '$';
	str[5] = '%';
	str[6] = '^';
	str[7] = '&';
	str[8] = '*';
	str[9] = '(';
	str[10] = ')';
	str[11] = '+';
	str[12] = '-';
	str[13] = '=';
	str[14] = '\0';
}

int	ft_type_caracter(char c)
{
	char	str[15];
	int		i;

	fill_str(str);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
