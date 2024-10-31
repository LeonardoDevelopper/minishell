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

//the my strin stake one more space in the last posiction
void	ft_echo(char **echo, int ac, t_info **info)
{
	int		i;
	int		k;
	int		j;
	char	**result;
	char	*value;

	value = NULL;
	value = malloc(sizeof(char *) * ft_strlen(echo[0]) * ft_count(echo) + 1);
	i = 1;
	k = 0;
	ft_echo1(echo, i, value);
	i = 0;
	result = ft_split_echo(value);
	if (ft_strcmp(result[i], "-n "))
	{
		i++;
		check_echo(result, info, i);
	}
	else
	{
		check_echo(result, info, i);
		printf("\n");
	}
	free(value);
}

void	check_double_quotes(char *str, t_info **info, int *j)
{
	(*j)++;
	while (str[*j] != 34)
	{
		if (str[*j] == '$')
		{
			double_asp(str, info, *j);
			while (str[*j] != 32 && str[*j] != 34 && str[*j] != 39)
			{
				(*j)++;
				if (str[*j] == '$')
					double_asp(str, info, *j);
			}
			(*j)--;
		}
		else
			printf("%c", str[*j]);
		(*j)++;
	}
}

void	check_single_quotes(char *str, int *j)
{
	(*j)++;
	while (str[*j] != 39)
	{
		printf("%c", str[*j]);
		(*j)++;
	}
}

void	check_dollar_sign(char **result, t_info **info, int i, int *j)
{
	expandecho(result, info, i);
	while (result[i][*j] != 32)
		(*j)++;
}

void	check_echo(char **result, t_info **info, int i)
{
	int	j;

	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			if (result[i][j] == 34)
				check_double_quotes(result[i], info, &j);
			else if (result[i][j] == 39)
				check_single_quotes(result[i], &j);
			else if (result[i][j] == '$')
				check_dollar_sign(result, info, i, &j);
			else
				printf("%c", result[i][j]);
			j++;
		}
		i++;
	}
}
