/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:04:27 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/13 17:33:22 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_exist(t_cmd *s_cmd, char *cmd)
{
	char	**dir;
	char	*full_path;
	int		i;

	i = -1;
	full_path = NULL;
	dir = split_dir(s_cmd);
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
	}
	else
	{
		cmd = ft_strjoin("/", cmd);
		while (dir && dir[++i])
		{
			full_path = ft_strjoin(dir[i], cmd);
			if (access(full_path, X_OK) == 0)
				return (free(cmd), free_matrix(dir), full_path);
			free(full_path);
		}
		free_matrix(dir);
	}
	return (free(cmd), NULL);
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
			//if (mat != NULL)
				//free_env_mat(mat);
			return (path);
		}
		i++;
	}
	if (mat != NULL)
		free_env_mat(mat);
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
