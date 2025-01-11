/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ech_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:55:07 by aborges           #+#    #+#             */
/*   Updated: 2024/12/15 12:56:31 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_dolar_quots(char **result, int i, int *j)
{
	int	size;
	int	k;

	size = 0;
	k = *j;
	while (result[i][k] == '$')
	{
		size++;
		k++;
	}
	if (size % 2 == 0 && size > 1)
	{
		write(1, "42", 2);
		*j = k + 1;
	}
	else
	{
		if (result[i][*j + 1] == '\0')
			write(1, "$", 1);
		*j = k - 1;
	}
}

int	ft_check_cots_quots(char **str)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 34)
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

void	check_single_quotes1(char *str, int *j)
{
	result_echo_quots(39, 0);
	(*j)++;
	while (str[*j] && str[*j] != 39)
	{
		result_echo_quots(str[*j], 0);
		(*j)++;
	}
	if (str[*j] == 39)
		result_echo_quots(39, 0);
}

char	*create_aux_string_quots(char *echo_quots_indice, int i)
{
	char	*aux;
	int		j;
	int		k;

	j = 0;
	if (echo_quots_indice[i] == 34 || echo_quots_indice[i] == 39)
		k = 0;
	else
		k = 0;
	aux = (char *)malloc(sizeof(char) * (ft_strlen(echo_quots_indice) + 1));
	if (!aux)
		return (NULL);
	while (echo_quots_indice[i + k] && echo_quots_indice[i + k] != 32
		&& echo_quots_indice[i + k] != 34 && echo_quots_indice[i + k] != 39
		&& echo_quots_indice[i + k] != '$')
	{
		if (echo_quots_indice[i + k] == 34 && j > 0)
			break ;
		aux[j] = echo_quots_indice[i + k];
		j++;
		i++;
	}
	aux[j] = '=';
	aux[j + 1] = '\0';
	return (aux);
}

void	check_double_quotes1(char *str, t_enviro **enviro, int *j)
{
	result_echo_quots(34, 0);
	(*j)++;
	while (str[*j] && str[*j] != 34)
	{
		if (str[*j] == '$')
		{
			double_asp_quots(str, enviro, *j);
			while (str[*j] && str[*j] != 32 && str[*j] != 34 && str[*j] != 39)
			{
				(*j)++;
				if (str[*j] == '$')
					double_asp_quots(str, enviro, *j);
			}
			(*j)--;
		}
		else
		{
			result_echo_quots(str[*j], 0);
		}
		(*j)++;
	}
	if (str[*j] == 34)
		result_echo_quots(34, 0);
}
