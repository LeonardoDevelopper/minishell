/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:25:51 by aborges           #+#    #+#             */
/*   Updated: 2024/10/23 12:33:14 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_aux(t_enviro **enviro, char **value)
{
	char	**result;
	int		i;

	i = 0;
	result = ft_split_echo(value);
	if (ft_strcmp(result[i], "-n "))
	{
		i++;
		check_echo(result, enviro, i);
	}
	else
	{
		check_echo(result, enviro, i);
		printf("\n");
	}
}

//the my strin stake one more space in the last posiction
int	ft_echo(char **echo, int ac, t_enviro **enviro)
{
	int		i;
	int		j;
	int		size;
	char	*value;

	if (!echo[1])
		printf("\n");
	if (!echo[1])
		return (1);
	value = NULL;
	i = 1;
	size = 0;
	while (echo[i])
	{
		size += ft_strlen(echo[i]);
		i++;
	}
	value = malloc(sizeof(char *) * size + ft_count(echo) - 1);
	if (!value)
		return (0);
	i = 1;
	ft_echo1(echo, i, value);
	ft_echo_aux(enviro, value);
	free(value);
	return (1);
}

void	check_double_quotes(char *str, t_enviro **enviro, int *j)
{
	(*j)++;
	while (str[*j] != 34)
	{
		if (str[*j] == '$')
		{
			double_asp(str, enviro, *j);
			while (str[*j] && str[*j] != 32 && str[*j] != 34 && str[*j] != 39)
			{
				(*j)++;
				if (str[*j] == '$')
					double_asp(str, enviro, *j);
			}
			(*j)--;
		}
		else
			printf("%c", str[*j]);
		(*j)++;
	}
}

void	aux_check_echo(char **result, t_enviro **enviro, int i, int *j)
{
	expandecho(result, enviro, i, *j);
	(*j)++;
	while (result[i][*j] && result[i][*j] != 32 && result[i][*j] != 34 &&
			result[i][*j] != 39 && result[i][*j + 1] != '$')
	{
		(*j)++;
	}
}

void	check_echo(char **result, t_enviro **enviro, int i)
{
	int	j;

	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			if (result[i][j] && result[i][j] == 34)
				check_double_quotes(result[i], enviro, &j);
			else if (result[i][j] && result[i][j] == 39)
				check_single_quotes(result[i], &j);
			else if (result[i][j] && result[i][j] == '$')
				aux_check_echo(result, enviro, i, &j);
			else if (result[i][j])
				printf("%c", result[i][j]);
			j++;
		}
		i++;
		if (result[i])
			printf(" ");
	}
}
