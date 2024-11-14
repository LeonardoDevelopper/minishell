/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 03:59:15 by aborges           #+#    #+#             */
/*   Updated: 2024/10/16 14:32:13 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_absolutway(char **cmd, char **env, t_enviro **enviro)
{
	int		j;
	int		i;
	pid_t	pid;
	char	**args;
	(void)enviro;
	args = NULL;
	args = (char **)malloc(sizeof(char) * ft_count(cmd) + 1);
	i = 0;
	args[i] = (char *)malloc(sizeof(char) * ft_strlen(cmd[i]) + 1);
	while (cmd[0][i])
	{
		if (cmd[0][i] == '/')
		{
			i++;
			j = 0;
			while (cmd[0][i] && cmd[0][i] != '/')
			{
				args[0][j] = cmd[0][i];
				i++;
				j++;
			}
		}
	}
	args[0][j] = '\0';
	j = 1;
	while (cmd[j])
	{
		args[j] = malloc(sizeof(char) * ft_strlen(cmd[j]) + 1);
		i = 0;
		while (cmd[j][i])
		{
			args[j][i] = cmd[j][i];
			i++;
		}
		args[j][i] = '\0';
		j++;
	}
	args[j] = malloc(sizeof(char) * ft_strlen(cmd[j]) + 1);
	args[j] = '\0';
	pid = fork();
	if (pid == -1)
	{
		perror("error!");
		return (0);
	}
	if (pid == 0)
	{
		if (execve(*cmd, args, env) == -1)
			return (0);
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	return (1);
}

int	ft_execute(char **cmd, int ac, char **env, t_enviro **enviro)
{
	t_enviro	*tmp;
	char		*args[2];
	char		*result;
	char		**paths;
	int			i;

	tmp = *enviro;
	while (tmp)
	{
		if (ft_searstr("PATH=", tmp->value))
		{
			paths = ft_split_path(tmp->value);
			break ;
		}
		tmp = tmp->next;
	}
	i = 0;
	while (paths[i])
	{
		result = ft_strjoin(paths[i], cmd[0]);
		args[0] = result;
		if (ac > 1)
		{
			args[1] = cmd[1];
			args[2] = NULL;
		}
		else
			args[1] = NULL;
		if (execve(result, args, env) == -1)
		{
			free(result);
			i++;
		}
		else
		{
			free(result);
		}
	}
	return (0);
}

int	execute_cmd(char **cmd, int ac, t_enviro **enviro, char **env)
{
	pid_t	pid;

	if (*cmd[0] == '/')
	{
		printf("Probabilidade de caminho absoluto\n");
		ft_absolutway(cmd, env, enviro);
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("error!");
			return (0);
		}
		if (pid == 0)
		{
			if (!ft_execute(cmd, ac, env, enviro))
				return (0);
		}
		else if (pid > 0)
			waitpid(pid, NULL, 0);
	}
	return (1);
}
