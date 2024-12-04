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

void	init_status(t_enviro **enviro, int value)
{
	char	**status;

	status = malloc(sizeof(char *) * 3);
	if (!status)
		return ;
	status[0] = malloc(sizeof(char) * 1024);
	if (!status[0])
	{
		free(status);
		return ;
	}
	ft_strcpy(status[0], "export");
	status[1] = malloc(sizeof(char) * 1024);
	if (!status[1])
	{
		free(status[0]);
		free(status);
		return ;
	}
	ft_strcpy(status[1], ft_strjoin("?=", ft_itoa(value)));
	status[2] = NULL;
	ft_export(status, ft_count(status), enviro);
	free(status[0]);
	free(status[1]);
	free(status);
}

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
	init_status(enviro, 0);
	return (1);
}
