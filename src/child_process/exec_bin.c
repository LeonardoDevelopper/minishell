/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:01:34 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/12 13:01:40 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*run_cmd_catch_output(char *cmd, t_enviro **enviro, char *env[])
{
	t_child_p	*child;
	int		pipe_fd[2];
	char	**full_cmd;
	char	*full_path;
	char	*output;
	int	builtins;
	int	*fd;




	full_cmd = ft_split(cmd, ' ');
	builtins = check_builtins(full_cmd, enviro, env);
	if (!builtins)
	{
		full_path = cmd_exist(full_cmd[0]);
		if (full_path)
		{
			pipe(pipe_fd);
			child = new_child_p(pipe_fd);
			if (child->pid == 0)
				run_child_p(full_path, full_cmd, child, env);
			fd = (int *)child->pipe_fd;
			close(fd[1]);
			waitpid(child->pid, &child->status, 0);
			output = read_stdout_child(fd[0]);
			free(child);
			free_matrix(full_cmd);
			return (output);
		}
		else
			printf("%s%s is not recognized on this shell\n", RED_TEXT, cmd);
	}
	return NULL;
}

void	run_cmd(char *cmd, t_enviro **enviro, char *env[])
{
	t_child_p	*child;
	char	**full_cmd;
	char	*full_path;
	int	builtins;

	full_cmd = ft_split(cmd, ' ');
	builtins = check_builtins(full_cmd, enviro, env);
	if (!builtins)
	{
		full_path = cmd_exist(full_cmd[0]);
		if (full_path)
		{
			child = new_child_p(NULL);
			if (child->pid == 0)
			{
				run_child_p(full_path, full_cmd, child, env);
				free(child);
			}
			waitpid(child->pid, &child->status, 0);
			free(child);
			free_matrix(full_cmd);
		}
		else
			printf("%s%s is not recognized on this shell\n", RED_TEXT, cmd);
	}
}
