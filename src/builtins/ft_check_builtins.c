/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 04:01:08 by aborges           #+#    #+#             */
/*   Updated: 2024/12/10 14:33:36 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtins_one(char **cmd, t_enviro **enviro, int k, int fd)
{
	int	count_arg;

	count_arg = ft_count(cmd);
	//if (ft_strcmp(remove_char(cmd[k], '"'), "cd"))
		//return (ft_cd(cmd, count_arg, enviro));
	if (ft_strcmp(remove_char(cmd[k], '"'), "export"))
		return (ft_export(cmd, count_arg, enviro));
	else if (ft_strcmp(remove_char(cmd[k], '"'), "unset"))
		return (ft_unset(cmd, count_arg, enviro));
	if (ft_strcmp(remove_char(cmd[k], '"'), "pwd"))
		return (ft_pwd(fd));
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

int	case_n(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	case_echo(char **cmd, t_enviro **enviro, char **env, int fd)
{
	char	*result_echo;

	result_echo = ft_echo(cmd, enviro);
	char	*aux = catch_cmd_args(result_echo);
	if (!aux)
		return (0);
	if (case_n(cmd[1]))
	{
		ft_putstr_fd(aux, fd);
		ft_putchar_fd('\n', fd);

	}
	else
	{
		ft_putstr_fd(aux, fd);
		ft_putchar_fd('\n', fd);
	}
	free(aux);
	return (0);
}

int	take_return(int value)
{
	int	result;

	if (value < 0 || value > 255)
	{
		result = value % 256;
		return ((unsigned char)result);
	}
	return (value);
}

int	check_builtins(t_prec *prec, t_enviro **enviro, char **env)
{
	int		count_arg;
	int		retur;
	char	**cmd;

	cmd = ft_split(prec->input, ' ');
	count_arg = ft_count(cmd);
	if (cmd[1] && (ft_check_cots(cmd) % 2 != 0))
	{
		print_chech_builtin(prec);
		free_matrix(cmd);
		return (1);
	}
	if (ft_strcmp(remove_char(cmd[0], '"'), "echo"))
	{
		if (case_n(cmd[0 + 1]) && !cmd[0 + 2])
		{
			free_matrix(cmd);
			return (1);
		}
		return (case_echo(cmd, enviro, env, prec->stdout));
	}
	else
	{
		retur = check_builtins_one(cmd, enviro, 0, prec->stdout);
		if (retur != 0)
			init_status(enviro, take_return(retur));
		free_matrix(cmd);
		return (retur);
	}
	exit(0);
}
