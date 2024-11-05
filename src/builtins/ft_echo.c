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
int	ft_echo(char **echo, int ac, t_info **info)
{
	int		i;
	int		k;
	int		j;
	char	**result;
	char	*value;

	if (!echo)
		return (0);
	value = NULL;

	i = 1;
	int size = 0;
	while (echo[i])
	{
		size += ft_strlen(echo[i]);
		i++;
	}
	value = malloc(sizeof(char *) * size + ft_count(echo) - 1);
	if (!value)
		return (0);
	i = 1;
	k = 0;
	ft_echo1(echo, i, value);
	i = 0;
	result = ft_split_echo(value);
	//printf("%s\n", result[0]);
	//printf("%s\n", result[1]);
	//printf("%s\n", result[2]);
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
	return (1);
}

void	check_double_quotes(char *str, t_info **info, int *j)
{
	(*j)++;
	while (str[*j] != 34)
	{
		if (str[*j] == '$')
		{
			double_asp(str, info, *j);
			while (str[*j] && str[*j] != 32 && str[*j] != 34 && str[*j] != 39)
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
	while (str[*j] && str[*j] != 39)
	{
		printf("%c", str[*j]);
		(*j)++;
	}
}

/* 
echo '"$HOME $USER" BETA BORGES 'OLA' "$USER"'
void	check_single_quotes(char *str, int *j)
{
	(*j)++; // Avança para o próximo caractere após a primeira aspas simples
	while (str[*j] && str[*j] != 39) // Verifica se str[*j] não é '\0' e não é uma aspas simples
	{
		printf("%c", str[*j]);
		(*j)++;
	}
	if (str[*j] == 39) // Avança além da aspas de fechamento, se ela existir
		(*j)++;
}
*/

void	check_echo(char **result, t_info **info, int i)
{
	int	j;

	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			if (result[i][j] && result[i][j] == 34)
				check_double_quotes(result[i], info, &j);
			else if (result[i][j] && result[i][j] == 39)
				check_single_quotes(result[i], &j);
			else if (result[i][j] && result[i][j] == '$')
			{
				expandecho(result, info, i, j);
				j++;
				while (result[i][j] && result[i][j] != 32 && result[i][j] != 34 &&
						result[i][j] != 39 && result[i][j + 1] != '$')
				{
					j++;
				}
			}
			else if (result[i][j])
				printf("%c", result[i][j]);
			j++;
		}
		i++;
		if (result[i])
			printf(" ");
	}
}
