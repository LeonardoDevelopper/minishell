/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:55:07 by aborges           #+#    #+#             */
/*   Updated: 2024/10/31 08:55:13 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	aux_cmpecho(char *aux, t_info *tmp)
{
	char	*result;
	int		i;

	result = NULL;
	if (ft_searstr(aux, tmp->value))
	{
		result = (char *)malloc(sizeof(char) * ft_strlen(tmp->value) + 1);
		ft_strcpy(result, tmp->value);
		i = 0;
		while (result[i] != '=')
			i++;
		while (result[i + 1])
		{
			printf("%c", result[i + 1]);
			i++;
		}
		if (result)
			free(result);
	}
}

char	*create_aux_string(char *echo_indice)
{
	char	*aux;
	int		j;
	int		k;

	j = 0;
	if (echo_indice[0] == 34 || echo_indice[0] == 39)
		k = 2;
	else
		k = 1;
	aux = (char *)malloc(sizeof(char) * (ft_strlen(echo_indice) + 1));
	if (!aux)
		return (NULL);
	while (echo_indice[j + k])
	{
		if (echo_indice[j + k] == 34 && j > 0)
			break ;
		aux[j] = echo_indice[j + k];
		j++;
	}
	aux[j] = '=';
	aux[j + 1] = '\0';
	return (aux);
}

void	expandecho(char **echo, t_info **info, int indice)
{
	t_info	*tmp;
	char	*aux;

	tmp = *info;
	aux = create_aux_string(echo[indice]);
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

	k = 0;
	while (echo[i])
	{
		j = 0;
		while (echo[i][j])
		{
			value[k] = echo[i][j];
			j++;
			k++;
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
