/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:21:58 by aborges           #+#    #+#             */
/*   Updated: 2024/11/08 10:22:01 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	aux_split_echo_one(char *str, int *var, char mat[250][250])
{
	if (str[var[0]] == 34)
	{
		mat[var[1]][var[2]] = str[var[0]];
		var[2]++;
		var[3] = 34;
		var[0]++;
	}
	else if (str[var[0]] == 39)
	{
		mat[var[1]][var[2]] = str[var[0]];
		var[2]++;
		var[3] = 39;
		var[0]++;
	}
	else
	{
		var[3] = 32;
	}
	while (str[var[0]] && str[var[0]] != var[3])
	{
		mat[var[1]][var[2]] = str[var[0]];
		var[2]++;
		var[0]++;
	}
}

void	aux_split_echo_two(char *str, int *var,
char mat[250][250], char **result)
{
	if ((var[0] + 1) < ft_strlen(str) && str[var[0] + 1]
		&& str[var[0]] != 32 && str[var[0] + 1] != var[3])
	{
		while (str[var[0] + 1] && str[var[0] + 1] != 32
			&& str[var[0] + 1] != var[3])
		{
			mat[var[1]][var[2]] = str[var[0]];
			var[2]++;
			var[0]++;
		}
	}
	if (str[var[0]])
	{
		mat[var[1]][var[2]] = str[var[0]];
		mat[var[1]][var[2] + 1] = '\0';
	}
	else
		mat[var[1]][var[2]] = '\0';
	result[var[1]] = mat[var[1]];
	var[0]++;
	var[1]++;
}

char	**ft_split_echo(char *str)
{
	static char	mat[250][250];
	static char	*result[250];
	int			var[4];

	var[0] = 0;
	var[1] = 0;
	ft_memset(mat, 0, sizeof(mat));
	ft_memset(result, 0, sizeof(result));
	while (str[var[0]] && str[var[0]] == 32)
		var[0]++;
	while (var[0] < ft_strlen(str))
	{
		var[2] = 0;
		aux_split_echo_one(str, var, mat);
		aux_split_echo_two(str, var, mat, result);
		while (var[0] < ft_strlen(str) && str[var[0]] && str[var[0]] == 32)
			var[0]++;
	}
	result[var[1]] = NULL;
	return (result);
}
