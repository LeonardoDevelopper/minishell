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
	char	*new_result;
	int		i;
	char	*end_result;

	result_echo(0, 1);
	i = 0;
	result = ft_split_echo(value);
	while (result[i])
	{
		new_result = epur_str(result[i]);
		if (case_n(new_result))
			i++;
		else
		{
			break ;
			free(new_result);
		}
		free(new_result);
	}
	check_echo(result, enviro, i);
}

char	*result_echo(int c, int reset)
{
	static char	str[250];
	static int	i;

	if (reset)
	{
		i = 0;
		str[0] = '\0';
	}
	if (i < 249 && c != '\0')
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_echo(char **echo, t_enviro **enviro)
{
	int			i;
	int			j;
	size_t		size;
	char		*value;

	if (!echo[1])
		printf("\n");
	if (!echo[1])
		return (NULL);
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
		return (NULL);
	i = 1;
	ft_echo1(echo, i, value);
	ft_echo_aux(enviro, value);
	free(value);
	return (epur_str(result_echo('\0', 0)));
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
				result_echo(result[i][j], 0);
			j++;
		}
		i++;
		if (result[i])
			result_echo(32, 0);
	}
}
