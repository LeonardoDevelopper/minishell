/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:55:07 by aborges           #+#    #+#             */
/*   Updated: 2024/12/15 12:56:31 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	aux_cmpecho(char *aux, t_enviro *tmp)
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
			result_echo(result[i + 1], 0);
			i++;
		}
		if (result)
			free(result);
	}
}

char	*create_aux_string(char *echo_indice, int i)
{
	char	*aux;
	int		j;
	int		k;

	j = 0;
	if (echo_indice[i] == 34 || echo_indice[i] == 39)
		k = 2;
	else
		k = 1;
	aux = (char *)malloc(sizeof(char) * (ft_strlen(echo_indice) + 1));
	if (!aux)
		return (NULL);
	while (echo_indice[i + k] && echo_indice[i + k] != 32
		&& echo_indice[i + k] != 34 && echo_indice[i + k] != 39
		&& echo_indice[i + k] != '$')
	{
		if (echo_indice[i + k] == 34 && j > 0)
			break ;
		aux[j] = echo_indice[i + k];
		j++;
		i++;
	}
	aux[j] = '=';
	aux[j + 1] = '\0';
	return (aux);
}

void	expandecho(char **echo, t_enviro **enviro, int indice, int i)
{
	t_enviro	*tmp;
	char		*aux;

	tmp = *enviro;
	aux = create_aux_string(echo[indice], i);
	if (!aux)
		return ;
	while (tmp)
	{
		aux_cmpecho(aux, tmp);
		tmp = tmp->next;
	}
	free(aux);
}

void	ft_echo1(char **echo, int i, char *value)
{
	int	k;
	int	j;
	int c = 0;
	int check = 0;

	k = 0;
	while (echo[i])
	{
		j = 0;
		while (echo[i][j])
		{
			if (echo[i][j] == '>')
			{
				check = 1;
				i++;
			}
			if ((echo [i][j] == 34 || echo[i][j] == 39) && check == 1)
			{
				c++;
			}

			if (c != 1)
			{
				value[k] = echo[i][j];
				j++;
				k++;
			}
			else
			{
				j++;
			}

		}
		i++;
		if (echo[i])
		{
			value[k] = 32;
			k++;
		}
		value[k] = '\0';
	}
}

void	check_single_quotes(char *str, int *j)
{
	(*j)++;
	while (str[*j] && str[*j] != 39)
	{
		result_echo(str[*j], 0);
		(*j)++;
	}
}
