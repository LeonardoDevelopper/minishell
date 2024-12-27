/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:04:27 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/15 13:58:09 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_absolute_path(char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/')
		|| (cmd[0] == '~' && cmd[1] == '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
	}
	return (NULL);
}

char	*cmd_exist(t_cmd *s_cmd, char *cmd)
{
	char	**dir;
	char	*full_path;
	int		i;

	i = 0;
	full_path = NULL;
	dir = split_dir(s_cmd);
	if (!is_absolute_path(cmd))
	{
		cmd = ft_strjoin("/", cmd);
		while (dir && dir[i])
		{
			full_path = ft_strjoin(dir[i], cmd);
			if (access(full_path, X_OK) == 0)
				return (free_matrix(dir), free(cmd),  full_path);
			free(full_path);
			i++;
		}
		free_matrix(dir);
		free(cmd);
	}
	return (NULL);
}

char	**original_env(char *path_cpy, char *path)
{
	char	*env;

	env = getenv("PATH");
	if (env)
	{
		ft_strcpy(path_cpy, env);
		path = ft_split(path_cpy, ':');
		return (path);
	}
	return (NULL);
}

char	**aborges_env(t_cmd *cmd, char *path_cpy, char *path)
{
	int		i;
	char	**mat;

	i = 0;
	mat = fill_max(&cmd->enviro);
	while (mat[i])
	{
		if (ft_searstr(mat[i], "PATH="))
		{
			mat[i] += 5;
			ft_strcpy(path_cpy, mat[i]);
			path = ft_split(path_cpy, ':');
			mat[i] -= 5;
			return (free_matrix(mat), path);
		}
		i++;
	}
	return (NULL);
}

char	**split_dir(t_cmd *cmd)
{
	char	path_cpy[1024];
	char	**path;

	if (!cmd)
		return (original_env(path_cpy, path));
	else
		return (aborges_env(cmd, path_cpy, path));
	return (NULL);
}
