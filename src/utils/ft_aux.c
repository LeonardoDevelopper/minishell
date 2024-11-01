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

char	**ft_split_echo(char *str)
{
	static char	mat[250][250];
	static char	*result[250];
	int			i;
	int			j;
	int			k;
	int			c;
	int			check = 0;

	i = 0;
	j = 0;
	ft_memset(mat, 0, sizeof(mat));
	memset(result, 0, sizeof(result));
	while (str[i] && str[i] == 32)
		i++;
	while (str[i])
	{
		k = 0;
		if (str[i] == 34)
		{
			mat[j][k] = str[i];
			k++;
			c = 34;
			i++;
		}
		else if (str[i] == 39)
		{
			mat[j][k] = str[i];
			k++;
			c = 39;
			i++;
		}
		else
		{
			c = 32;
		}
		while (str[i] && str[i] != c)
		{
			mat[j][k] = str[i];
			k++;
			i++;
		}
		if (str[i + 1] && str[i + 1] != 32)
		{
			while (str[i] && str[i] != 32)
			{
				mat[j][k] = str[i];
				k++;
				i++;
			}
		}
		mat[j][k] = str[i];
		mat[j][k+1] = '\0';
		result[j] = mat[j];
		i++;
		j++;
		while (str[i] && str[i] == 32)
			i++;
	}
	result[j] = NULL;
	return (result);
}

//split to path
char	**ft_split_path(char *path)
{
	static char	mat[250][250];
	static char	*result[250];
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	ft_memset(mat, 0, sizeof(mat));
	while (path[i] && (path[i] != '='))
		i++;
	i++;
	while (path[i])
	{
		k = 0;
		while (path[i] && path[i] != ':')
		{
			mat[j][k] = path[i];
			i++;
			k++;
		}
		mat[j][k] = '/';
		result[j] = mat[j];
		j++;
		i++;
	}
	result[j] = NULL;
	return (result);
}
