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
	pwd[1] = ft_strjoin("PWD=", temp);
	pwd[2] = NULL;
	free(temp);
	if (!pwd[1])
		free(pwd[0]);
	if (!pwd[1])
		return ;
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
			printf("cd: string not in pwd\n");
		ft_new_pwd(pwd, enviro);		
		ft_export(pwd, 2, enviro);
	}
	else if (ft_count(cd) == 2)
	{
		if (chdir(ft_echo(cd, enviro)) == -1)
			printf("cd: string not in %s\n", cd[1]);
		ft_new_pwd(pwd, enviro);
		ft_export(pwd, 2, enviro);
	}
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
	ft_condition_cd(cd, oldpwd, pwd, enviro);
	ft_export(oldpwd, 2, enviro);
	free_cd(pwd, oldpwd);
}

int	ft_cd(char **cd, int ac, t_enviro **enviro)
{
	char	**oldpwd;
	char	**pwd;

	if (ac > 2)
	{
		printf("cd: too many arguments");
		return (0);
	}
	oldpwd = (char **)malloc(2 * sizeof(char *));
	if (!oldpwd)
		return (0);
	pwd = (char **)malloc(2 * sizeof(char *));
	if (!pwd)
	{
		free(oldpwd);
		return (0);
	}
	ft_start_cd(cd, oldpwd, pwd, enviro);
	return (1);
}
