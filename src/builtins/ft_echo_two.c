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
	t_info	*tmp;
	char	*aux;
	int		j;

	tmp = *info;
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
