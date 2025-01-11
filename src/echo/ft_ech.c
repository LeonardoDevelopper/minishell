/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ech.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:25:51 by aborges           #+#    #+#             */
/*   Updated: 2025/01/11 10:00:24 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_quots_aux(t_enviro **enviro, char **value)
{
	char	**result;
	char	*new_result;
	int		i;

	result_echo_quots(0, 1);
	i = 0;
	result = ft_split_echo(*value);
	while (result[i])
	{
		new_result = epur_str(result[i]);
		if (case_n(new_result))
			i++;
		else
		{
			free(new_result);
			break ;
		}
		free(new_result);
	}
	check_echo_quots(result, enviro, i);
}

void	aux_check_echo_quots(char **result, t_enviro **enviro, int i, int *j)
{
	check_dolar(result, i, j);
	expandecho_quots(result, enviro, i, *j);
	(*j)++;
	while (result[i][*j] && result[i][*j] != 32 && result[i][*j] != 34 &&
			result[i][*j] != 39 && result[i][*j + 1] != '$')
	{
		(*j)++;
	}
}

void	check_echo_quots(char **result, t_enviro **enviro, int i)
{
	int	j;

	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			if (result[i][j] && result[i][j] == 34)
				check_double_quotes1(result[i], enviro, &j);
			else if (result[i][j] && result[i][j] == 39)
				check_single_quotes1(result[i], &j);
			else if (result[i][j] && result[i][j] == '$')
				aux_check_echo_quots(result, enviro, i, &j);
			else if (result[i][j])
				result_echo_quots(result[i][j], 0);
			j++;
		}
		i++;
		if (result[i])
			result_echo_quots(32, 0);
	}
}

void	aux_cmpecho_quots(char *aux, t_enviro *tmp)
{
	char	*result;
	int		i;

	result = NULL;
	if (ft_searstr(aux, tmp->value))
	{
		result = (char *)malloc(sizeof(char) * ft_strlen(tmp->value) + 1);
		if (!result)
			return ;
		ft_strcpy(result, tmp->value);
		i = 0;
		while (result[i] != '=')
			i++;
		while (result[i + 1])
		{
			result_echo_quots(result[i + 1], 0);
			i++;
		}
		if (result)
			free(result);
	}
}
