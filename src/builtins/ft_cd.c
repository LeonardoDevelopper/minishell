/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:09:02 by aborges           #+#    #+#             */
/*   Updated: 2024/11/12 15:09:05 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_oldpwd(char **oldpwd, t_enviro **enviro)
{
	char	*pwd_value;
	char	*temp;

	oldpwd[0] = (char *)malloc(strlen("export") + 1);
	if (!oldpwd[0])
		return ;
	ft_strcpy(oldpwd[0], "export");
	pwd_value = search_env("PWD=", enviro);
	if (!pwd_value)
	{
		free(oldpwd[0]);
		oldpwd[0] = NULL;
		return ;
	}
	temp = ft_strjoin("OLD", pwd_value);
	if (!temp)
	{
		free(oldpwd[0]);
		return ;
	}
	oldpwd[1] = temp;
	oldpwd[2] = NULL;
}

void	ft_condition_cd_aux(char **cd, char **pwd,
		t_enviro **enviro)
{
	if (chdir(cd[1]) == -1)
	{
		if (chdir(ft_echo(cd, enviro)) == -1)
		{
			printf("cd: string not in %s\n", cd[1]);
			return (1);
		}
	}
	ft_new_pwd(pwd, enviro);
	ft_export(pwd, 2, enviro);
}

int	ft_condition_cd(char **cd, char **oldpwd, char **pwd,
		t_enviro **enviro)
{
	char	*home;

	if (ft_count(cd) == 1)
	{
		home = getenv("HOME");
		if (!home)
		{
			free(oldpwd);
			free(pwd);
			return (0);
		}
		if (chdir(home) == -1)
		{
			printf("cd: string not in pwd\n");
			return (1);
		}
		ft_new_pwd(pwd, enviro);
		ft_export(pwd, 2, enviro);
	}
	else
		ft_condition_cd_aux(cd, pwd, enviro);
	return (1);
}

int	ft_start_cd(char **cd, char **oldpwd, char **pwd,
		t_enviro **enviro)
{
	oldpwd[0] = NULL;
	oldpwd[1] = NULL;
	pwd[0] = NULL;
	pwd[1] = NULL;
	ft_oldpwd(oldpwd, enviro);
	if (ft_condition_cd(cd, oldpwd, pwd, enviro) == -1)
		return (-1);
	ft_export(oldpwd, 2, enviro);
	free_cd(pwd, oldpwd);
	return (0);
}

int	ft_cd(char **cd, int ac, t_enviro **enviro)
{
	char	**oldpwd;
	char	**pwd;

	oldpwd = (char **)malloc(2 * sizeof(char *));
	if (!oldpwd)
		return (0);
	pwd = (char **)malloc(2 * sizeof(char *));
	if (!pwd)
	{
		free(oldpwd);
		return (0);
	}
	return (ft_start_cd(cd, oldpwd, pwd, enviro));
}
