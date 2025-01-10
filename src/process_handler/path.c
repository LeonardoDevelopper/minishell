/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:04:27 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/10 20:37:58 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*is_absolute_path(char *cmd)
{
	char	*home;
	char	*tmp;

	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(cmd) + 1));
		ft_strcpy(tmp, cmd);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
	}
	else if ((cmd[0] == '~' && cmd[1] == '/'))
	{
		home = getenv("HOME");
		tmp = ft_strjoin(home, "/");
		tmp = ft_strjoin_ptr(tmp, cmd + 2);
		cmd -= 2;
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
	}
	return (NULL);
}

char	*cmd_exist(t_cmd *s_cmd, char *cmd)
{
	char	**dir;
	char	*full_path;
	int		i;

	i = 0;
	dir = split_dir(s_cmd);
	full_path = is_absolute_path(cmd);
	if (full_path)
		return (free_matrix(dir), full_path);
	else
	{
		while (dir && dir[i])
		{
			dir[i] = ft_strjoin_ptr(dir[i], "/");
			full_path = ft_strjoin(dir[i], cmd);
			if (access(full_path, X_OK) == 0)
				return (free_matrix(dir), full_path);
			free(full_path);
			i++;
		}
		free_matrix(dir);
	}
	return (NULL);
}

char	**original_env(char *path_cpy, char **path)
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

char	**aborges_env(t_cmd *cmd, char *path_cpy, char **path)
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
	free_matrix(mat);
	return (NULL);
}

char	**split_dir(t_cmd *cmd)
{
	char	path_cpy[1024];
	char	**path;

	path = NULL;
	if (!cmd)
		return (original_env(path_cpy, path));
	else
		return (aborges_env(cmd, path_cpy, path));
	return (NULL);
}
