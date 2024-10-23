/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:04:27 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/12 13:04:28 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_exist(char *cmd)
{
	char	**dir;
	char	*full_path;
	int	i;

	i = 0;
	full_path = NULL;
	dir = split_dir();
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
	}
	else if (cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
	}
	else
	{
		cmd = ft_strjoin("/", cmd);
		while (dir[i])
		{
			full_path = ft_strjoin(dir[i++], cmd);
			if (access(full_path, X_OK) == 0)
			{
				free(cmd);
				free_matrix(dir);
				return (full_path);
			}
			free(full_path);
		}
			free(cmd);
			free_matrix(dir);
	}
	return (NULL);
}

char	**split_dir(void)
{
	char *env;
	char path_cpy[1024];
	char	**path;

	env = getenv("PATH");
	if (env)
	{
		strncpy(path_cpy, env, sizeof(path_cpy));
		path_cpy[sizeof(path_cpy) - 1] = '\0';
		path = ft_split(path_cpy, ':');
		return (path);
	}
	return (NULL);	
}
