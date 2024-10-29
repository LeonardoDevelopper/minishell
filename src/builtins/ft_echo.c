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

int	print_echo(char **echo, t_info **info, int indice)
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

	int open = 0;
	j = 0;
	i = 0;
	if (ft_strcmp(result[i], "-n"))
	{
		while (result[i + 1])
		{
			if (result[i + 1][0] == '$')
				expandecho(result, info, i + 1);
			else
				//auxecho(result, info, i + 1);
			i++;
		}
	}
	else
	{
		while (result[i])
		{
			j = 0;
			while (result[i][j])
			{
				if (result[i][j] == 34)
				{
					j++;
					//printf("casragj: %c", result[i][j]);
					while (result[i][j] != 34)
					{
						if (result[i][j] == '$')
						{
							double_asp(result[i], info, j);
							while (result[i][j] != 32 && result[i][j] != 34 && result[i][j] != 39)
								j++;
							j = j - 1;
						}
						else
							printf("%c", result[i][j]);
						j++;
					}
				}
				else if (result[i][j] == 39)
				{
					j++;
					while (result[i][j] != 39)
					{
						printf("%c", result[i][j]);
						j++;
					}
				}
				else if (result[i][j] == '$')
				{
					expandecho(result, info, i);
					while (result[i][j] != 32)
						j++;
				}
				else
				{
					printf("%c", result[i][j]);
				}
				j++;
			}
			i++;
		}
		printf("\n");
	}
	
	printf("\n");
}

void	double_asp(char *str, t_info **info, int i)
{
	if (str[i] == '$')
	{
		i++;
		resave(str, info, i);
	}
}

void	resave(char *str, t_info **info, int i)
{
	t_info *tmp;
	char	*aux;
	int	k;
	int	j;

	tmp = *info;
	aux = NULL;
	aux = (char *)malloc(sizeof(char) * ft_strlen(str + 1));
	j = 0;
	k = 1;

	while (str[i] && (str[i] != 32 && str[i] != 34 && str[i] != 39))
	{
		aux[j] = str[i];
		i++;
		j++;
	}
	aux[j] = '=';
	//printf("\nSAVE: %s\n", aux);
	while (tmp)
	{
		aux_cmpecho(aux, tmp);
		tmp = tmp->next;
	}
	if (aux)
		free(aux);
}
////////////// ECHO fim