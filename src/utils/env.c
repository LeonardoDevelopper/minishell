/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:07:49 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/23 14:07:51 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fill_env(t_enviro **enviro, char **env)
{
	t_enviro	*tmp;
	int			i;

	*enviro = NULL;
	i = 0;
	while (env[i])
	{
		tmp = (t_enviro *)malloc(sizeof(t_enviro));
		if (!tmp)
			return (0);
		tmp->indice = i;
		tmp->value = (char *)malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		if (!tmp->value)
		{
			free(tmp);
			return (0);
		}
		ft_strcpy(tmp->value, env[i]);
		tmp->next = *enviro;
		*enviro = tmp;
		i++;
	}
	return (1);
}
