/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 04:01:08 by aborges           #+#    #+#             */
/*   Updated: 2024/10/23 12:22:58 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtins_one(char **cmd, t_enviro **enviro, int k, int count_arg)
{
	if (ft_strcmp(cmd[k], "cd"))
		return (ft_cd(cmd, count_arg, enviro));
	else if (ft_strcmp(cmd[k], "export"))
		ft_export(cmd, count_arg, enviro);
	else if (ft_strcmp(cmd[k], "unset"))
		ft_unset(cmd, count_arg, enviro);
	if (ft_strcmp(cmd[k], "pwd"))
		return (ft_pwd(count_arg));
	else if (ft_strcmp(cmd[k], "env"))
	{
		ft_env(count_arg, cmd, enviro);
		return (1);
	}
	else if (ft_strcmp(cmd[k], "exit"))
		ft_exit(cmd, count_arg);
	else
		return (0);
}

int	case_echo(char **cmd, t_enviro **enviro, char **env)
{
	char	*result_echo;

	result_echo = ft_echo(cmd, enviro);
	if (!result_echo)
		return (0);
	if (ft_strcmp(cmd[1], "-n"))
		printf("%s", result_echo);
	else
	{
		printf("%s", result_echo);
		printf("\n");
	}
	free(result_echo);
	return (1);
}

int	check_builtins(char **cmd, t_enviro **enviro, char **env)
{
	int	count_arg;
	int	k;

	k = 0;
	env = env;
	count_arg = ft_count(cmd);
	if (ft_strcmp(cmd[k], "echo"))
	{
		if (ft_strcmp(cmd[k + 1], "-n") && !cmd[k + 2])
			return (1);
		return (case_echo(cmd, enviro, env));
	}
	else if (!check_builtins_one(cmd, enviro, k, count_arg))
		return (0);
	return (1);
}
