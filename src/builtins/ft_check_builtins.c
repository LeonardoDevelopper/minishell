/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 04:01:08 by aborges           #+#    #+#             */
<<<<<<< .merge_file_6AdUTy
/*   Updated: 2025/01/11 16:02:52 by lleodev          ###   ########.fr       */
=======
/*   Updated: 2025/01/13 12:11:24 by lleodev          ###   ########.fr       */
>>>>>>> .merge_file_th898I
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
		return (ft_export(cmd, count_arg, enviro));
	else if (ft_strcmp(remove_char(cmd[k], '"'), "unset"))
		return (ft_unset(cmd, count_arg, enviro));
	else if (ft_strcmp(remove_char(cmd[k], '"'), "pwd"))
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
	return (0);
}

int	case_n(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	if (str[i] == '-' && str[i + 1] != '\0')
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

	env = env;
	if (ft_count(cmd) == 1)
	{
		printf("\n");
		return (0);
	}
	result_echo = epur_str(ft_echo(cmd, enviro));
	if (!result_echo)
		return (0);
	if (case_n(cmd[1]))
		ft_putstr_fd(result_echo, fd);
	else
	{
		ft_putstr_fd(result_echo, fd);
		printf("\n");
	}
	free(result_echo);
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
	int		retur;
	char	**cmd;

	cmd = ft_split(prec->input, ' ');
	retur = 0;
	if (cmd[1] && (ft_check_cots(cmd) % 2 != 0))
		retur = print(prec);
	else if (ft_strcmp(remove_char(cmd[0], '"'), "echo")
		|| ft_strcmp(remove_char(cmd[0], 39), "echo"))
	{
		if (case_n(cmd[1]) && !cmd[2])
			retur = 1;
		else if (case_n(cmd[1]) && !cmd[2])
			retur = case_echo(cmd, enviro, env, prec->stdout);
		else
			retur = case_echo(cmd, enviro, env, prec->stdout);
	}
	else
	{
		retur = check_builtins_one(cmd, enviro, 0, prec->stdout);
		if (retur != 0)
			init_status(enviro, take_return(retur));
	}
	free_matrix(cmd);
	return (retur);
}