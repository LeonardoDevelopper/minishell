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

int	check_builtins(char **cmd, t_info **info, char **env)
{
	int	count_arg;
	int	k;

	k = 0;
	count_arg = ft_count(cmd);
	if (ft_strcmp(cmd[k], "pwd"))
		ft_pwd(count_arg);
	else if (ft_strcmp(cmd[k], "env"))
		ft_env(count_arg, cmd, info);
	else if (ft_strcmp(cmd[k], "exit"))
		ft_exit(cmd, count_arg);
	else if (ft_strcmp(cmd[k], "echo"))
		ft_echo(cmd, count_arg, info);
	else if (ft_strcmp(cmd[k], "cd"))
		ft_cd(cmd, count_arg);
	else if (ft_strcmp(cmd[k], "export"))
		ft_export(cmd, count_arg, info);
	else if (ft_strcmp(cmd[k], "unset"))
		ft_unset(cmd, count_arg, info);
	else
		return (0);
	//else if (!execute_cmd(cmd, count_arg, info, env))
	//	return (0);
	return (1);
}
