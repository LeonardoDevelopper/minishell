/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:07:49 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/15 07:39:20 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_status(t_enviro **enviro, int value)
{
	char	**status;
	char	*str_itoa;
	char	*str_join;
	int		n;

	status = malloc(sizeof(char *) * 3);
	if (!status)
		return ;
	status[0] = malloc(sizeof(char) * 240);
	if (!status[0])
	{
		free(status);
		return ;
	}
	ft_strcpy(status[0], "export");
	status[1] = malloc(sizeof(char) * 250);
	if (!status[1])
	{
		free(status[0]);
		free(status);
		return ;
	}
	if (value < 0)
		n = value + 255;
	n = value % 255;
	str_itoa = ft_itoa(n);
	if (!str_itoa)
	{
		free(status[1]);
		free(status[0]);
		free(status);
		return ;
	}
	str_join = ft_strjoin("?=", str_itoa);
	if (!str_join)
	{
		free(str_itoa);
		free(status[1]);
		free(status[0]);
		free(status);
		return ;
	}
	ft_strcpy(status[1], str_join);
	status[2] = NULL;
	ft_export(status, ft_count(status), enviro);
	free(str_itoa);
	free(str_join);
	free(status[1]);
	free(status[0]);
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

char	**fill_max(t_enviro **enviro)
{
	int			i;
	t_enviro	*tmp;
	char		**new_mat;

	new_mat = ft_calloc(sizeof(char *), (ft_listsize(enviro) + 1));
	if (new_mat == NULL)
		return (NULL);
	tmp = *enviro;
	i = 0;
	while (tmp != NULL)
	{
		new_mat[i] = ft_calloc(sizeof(char), (ft_strlen(tmp->value) + 1));
		if (new_mat[i] == NULL)
		{
			free_env_mat(new_mat);
			return (NULL);
		}
		ft_strcpy(new_mat[i], tmp->value);
		tmp = tmp->next;
		i++;
	}
	return (new_mat);
}
