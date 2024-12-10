/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:05:23 by aborges           #+#    #+#             */
/*   Updated: 2024/11/12 15:55:54 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_enviro_list(t_enviro **enviro)
{
	t_enviro	*tmp;

	while (*enviro)
	{
		tmp = (*enviro)->next;
		free((*enviro)->value);
		free(*enviro);
		*enviro = tmp;
	}
}

void	free_env_mat(char **mat)
{
	int	i;

	if (!mat)
		return ;
	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}


void	free_cd(char **pwd, char **oldpwd)
{
	if (pwd)
	{
		if (pwd[0])
			free(pwd[0]);
		if (pwd[1])
			free(pwd[1]);
		free(pwd);
	}
	if (oldpwd)
	{
		if (oldpwd[0])
			free(oldpwd[0]);
		if (oldpwd[1])
			free(oldpwd[1]);
		free(oldpwd);
	}
}

