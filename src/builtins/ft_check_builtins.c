/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 04:01:08 by aborges           #+#    #+#             */
/*   Updated: 2024/11/30 11:19:01 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtins_one(char **cmd, t_enviro **enviro, int k, int fd)
{
	int	count_arg;

	count_arg = ft_count(cmd);
	if (ft_strcmp(remove_char(cmd[k], '"'), "cd"))
		return (ft_cd(cmd, count_arg, enviro));
	else if (ft_strcmp(remove_char(cmd[k], '"'), "export"))
		return (ft_export(cmd, count_arg, enviro, fd));
	else if (ft_strcmp(remove_char(cmd[k], '"'), "unset"))
		return (ft_unset(cmd, count_arg, enviro));
	if (ft_strcmp(remove_char(cmd[k], '"'), "pwd"))
		return (ft_pwd(count_arg, fd));
	else if (ft_strcmp(remove_char(cmd[k], '"'), "env"))
	{
		ft_env(count_arg, cmd, enviro, fd);
		return (1);
	}
	else if (ft_strcmp(remove_char(cmd[k], '"'), "exit"))
		ft_exit(cmd, count_arg, enviro, fd);
	else
		return (0);
}

int	case_echo(char **cmd, t_enviro **enviro, char **env, int fd)
{
	char	*result_echo;

	result_echo = ft_echo(cmd, enviro);
	if (!result_echo)
		return (0);
	if (ft_strcmp(cmd[1], "-n"))
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
		ft_putstr_fd(result_echo, fd);
	}
	else
	{
		ft_putstr_fd(result_echo, fd);
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

int	check_builtins(t_prec *prec, t_enviro **enviro, char **env)
{
	int		count_arg;
	int		k;
	int		retur;
	char	**cmd;
	int		fd;

	k = 0;
	cmd = ft_split(prec->input, ' ');
	count_arg = ft_count(cmd);
	if (cmd[1] && (ft_check_cots(cmd) % 2 != 0))
	{
		ft_putstr_fd("Invalid arg! ", prec->stdout);
		ft_putstr_fd("ft_check_cots(cmd)", prec->stdout);
		printf("\n");
		return (1);
	}
	if (ft_strcmp(remove_char(cmd[k], '"'), "echo"))
	{
		if (ft_strcmp(cmd[k + 1], "-n") && !cmd[k + 2])
			return (1);
		return (case_echo(cmd, enviro, env, prec->stdout));
	}
	else
	{
		retur = check_builtins_one(cmd, enviro, k, prec->stdout);
		if (retur != 0)
			init_status(enviro, retur);
		return (retur);
	}
}
