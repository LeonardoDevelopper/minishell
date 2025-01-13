/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ech_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:55:22 by aborges           #+#    #+#             */
/*   Updated: 2025/01/11 10:00:49 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*result_echo_quots(int c, int reset)
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

void	expandecho_quots(char **echo_quots,
		t_enviro **enviro, int indice, int i)
{
	t_enviro	*tmp;
	char		*aux;

	tmp = *enviro;
	aux = create_aux_string(echo_quots[indice], i);
	if (!aux)
		return ;
	while (tmp)
	{
		aux_cmpecho_quots(aux, tmp);
		tmp = tmp->next;
	}
	free(aux);
}

void	ft_echo_quots1(char **echo_quots, int i, char *value)
{
	int	var[5];

	var[0] = 0;
	var[1] = 0;
	var[2] = 0;
	var[3] = i;
	while (echo_quots[var[3]])
	{
		var[4] = 0;
		while (echo_quots[var[3]][var[4]])
		{
			case_redirect_quots(echo_quots, value, var);
		}
		var[3]++;
		if (echo_quots[var[3]] && var[2] == 0)
		{
			value[var[0]] = ' ';
			var[0]++;
		}
	}
	value[var[0]] = '\0';
}

void	double_asp_quots(char *str, t_enviro **enviro, int i)
{
	if (str[i] && str[i] == '$')
	{
		i++;
		resave_quots(str, enviro, i);
	}
}

void	resave_quots(char *str, t_enviro **enviro, int i)
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
		aux_cmpecho_quots(aux, tmp);
		tmp = tmp->next;
	}
	if (aux)
		free(aux);
}
