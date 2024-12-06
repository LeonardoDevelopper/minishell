/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:17:52 by aborges           #+#    #+#             */
/*   Updated: 2024/11/27 09:17:54 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_new_pwd_aux(char **pwd, t_enviro **enviro, char *temp)
{
	pwd[1] = ft_strjoin("PWD=", temp);
	pwd[2] = NULL;
	free(temp);
	if (!pwd[1])
	{
		free(pwd[0]);
		return ;
	}
}

void	ft_new_pwd(char **pwd, t_enviro **enviro)
{
	char	*temp;

	pwd[0] = (char *)malloc(strlen("export") + 1);
	if (!pwd[0])
	{
		free(pwd);
		return ;
	}
	ft_strcpy(pwd[0], "export");
	temp = (char *)malloc(1024);
	if (!temp)
	{
		free(pwd[0]);
		return ;
	}
	if (getcwd(temp, 1024) == NULL)
	{
		perror("Erro em getcwd");
		free(pwd[0]);
		free(temp);
		return ;
	}
	ft_new_pwd_aux(pwd, enviro, temp);
}
