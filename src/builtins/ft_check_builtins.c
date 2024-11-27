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
	if (ft_strcmp(remove_char(cmd[k], '"'), "cd"))
		return (ft_cd(cmd, count_arg, enviro));
	else if (ft_strcmp(remove_char(cmd[k], '"'), "export"))
		return (ft_export(cmd, count_arg, enviro));
	else if (ft_strcmp(remove_char(cmd[k], '"'), "unset"))
		return (ft_unset(cmd, count_arg, enviro));
	if (ft_strcmp(remove_char(cmd[k], '"'), "pwd"))
		return (ft_pwd(count_arg));
	else if (ft_strcmp(remove_char(cmd[k], '"'), "env"))
	{
		ft_env(count_arg, cmd, enviro);
		return (1);
	}
	else if (ft_strcmp(remove_char(cmd[k], '"'), "exit"))
		ft_exit(cmd, count_arg, enviro);
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
	return (0);
}

int	ft_check_cots(char **str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		int	j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 34)
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

int	check_builtins(char **cmd, t_enviro **enviro, char **env)
{
	int	count_arg;
	int	k;
	int	retur;

	k = 0;
	if (cmd[1] && (ft_check_cots(cmd) % 2 != 0))
	{
		printf("Invalid arg! %d\n", ft_check_cots(cmd));
		return (1);
	}
	count_arg = ft_count(cmd);
	if (ft_strcmp(remove_char(cmd[k], '"'), "echo"))
	{
		if (ft_strcmp(cmd[k + 1], "-n") && !cmd[k + 2])
			return (1);
		return (case_echo(cmd, enviro, env));
	}
	else
	{
		retur = check_builtins_one(cmd, enviro, k, count_arg);
		if (retur != 0)
			init_status(enviro, retur);
		return (retur);
	}
}
