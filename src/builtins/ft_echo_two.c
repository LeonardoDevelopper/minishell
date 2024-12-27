/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:55:22 by aborges           #+#    #+#             */
/*   Updated: 2024/10/31 08:55:24 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	double_asp(char *str, t_enviro **enviro, int i)
{
	if (str[i] && str[i] == '$')
	{
		i++;
		resave(str, enviro, i);
	}
}

void	check_double_quotes(char *str, t_enviro **enviro, int *j)
{
	(*j)++;
	while (str[*j] && str[*j] != 34)
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
		{
			result_echo(str[*j], 0);
		}
		(*j)++;
	}
}

void	resave(char *str, t_enviro **enviro, int i)
{
	t_enviro	*tmp;
	char		*aux;
	int			j;

	tmp = *enviro;
	aux = NULL;
	aux = (char *)malloc(sizeof(char) * ft_strlen(str + 1));
	j = 0;
	while (str[i] && (str[i] != 32 && str[i]
			!= 34 && str[i] != 39 && str[i] != '$'))
	{
		aux[j] = str[i];
		i++;
		j++;
	}
	aux[j] = '=';
	while (tmp)
	{
		aux_cmpecho(aux, tmp);
		tmp = tmp->next;
	}
	if (aux)
		free(aux);
}

int	ft_check_cots(char **str)
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

void	check_dolar(char **result, int i, int *j)
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
