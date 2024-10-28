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

void	aux_cmpecho(char *aux, t_info *tmp)
{
	char *result;
	int	i;

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
		if (result[i])
			printf(" ");
		if (result)
			free(result);
	}
}

void	expandecho(char **echo, t_info **info, int	indice)
{
	t_info *tmp;
	char	*aux;
	int	k;
	int	j;

	tmp = *info;
	aux = NULL;
	aux = (char *)malloc(sizeof(char) * ft_strlen(echo[indice]) + 1);
	j = 0;
	k = 1;

	if (echo[indice][j] == 34 || echo[indice][j] == 39)
	{
		k++;
	}
	while (echo[indice][j + 1])
	{
		if (echo[indice][j + k] == 34 && j > 0)
			break ;
		aux[j] = echo[indice][j + k];
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

void	auxecho(char **echo, t_info **info, int indice)
{
	int	i;
	int	j;

	i = indice;
	j = 0;
	if (echo[i][j] == 34)
	{
		expandecho(echo, info, indice);
		return ;
	}
	while (echo[i][j])
	{
		if (echo[i][j] && echo[i][j] != 34)
			printf("%c", echo[i][j]);
		j++;
	}
}



void	ft_echo(char **echo, int ac, t_info **info)
{
	int	i;
	char	**result;
	char	*value;

	value = NULL;
	value = malloc(sizeof(char *) * ft_strlen(echo[0]) * ft_count(echo) + 1);
	printf("\n\n");
	i = 1;
	int k = 0;
	int j;
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
	}
	i = 0;
	result = ft_split_echo(value);
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
/*
	i = 1;
	ac = ac;
	if (ac > 1 && ft_strcmp(echo[1], "-n"))
	{
		while (echo[i + 1])
		{
			if (echo[i + 1][0] == '$')
				expandecho(echo, info, i + 1);
			else
				auxecho(echo, info, i + 1);
			i++;
		}
	}
	else if (ac > 1)
	{
		while (echo[i])
		{
			if (echo[i][0] == '$')
				expandecho(echo, info, i);
			else
				auxecho(echo, info, i);
			if (echo[i + 1])
				printf(" ");
			i++;
		}
		printf("\n");
	}
	else
		printf("\n");*/
}
////////////// ECHO fim