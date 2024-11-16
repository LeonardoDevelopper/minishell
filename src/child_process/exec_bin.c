/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:01:34 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/16 19:50:30 by lleodev          ###   ########.fr       */
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
				run_child_p_test(full_path, full_cmd, child, env);
			fd = (int *)child->pipe_fd;
			close(fd[1]);
			waitpid(child->pid, &child->status, 0);
			output = read_stdout_child(fd[0]);
			free(child);
			free_matrix(full_cmd);
			return (output);
		}
	}
	return (NULL);
}

void	run_cmd_test(t_prec *prec, t_enviro **enviro, char *env[])
{
	t_child_p	*child;
	int			builtins;
	int			pipe_fd[2];

	builtins = check_builtins(prec->args, enviro, env);
	if (!builtins)
	{
		pipe_fd[0] = prec->stdin;
		pipe_fd[1] = prec->stdout;
		child = new_child_p(pipe_fd);
		if (child->pid == 0)
		{
			run_child_p(prec, child, env);
			free(child);
		}
		waitpid(child->pid, &child->status, 0);
		free(child);
	}
}

void	run_cmd(t_cmd *cmd, char *env[])
{
	t_child_p	*child;
	int			builtins;

	builtins = check_builtins(cmd->cmd_splited, &cmd->enviro, env);
	if (!builtins)
	{
		child = new_child_p(NULL);
		if (child->pid == 0)
		{
			run_child_p(cmd->precedence[0], child, env);
			free(child);
		}
		waitpid(child->pid, &child->status, 0);
		free(child);
		free_matrix(cmd->cmd_splited);
	}
}

void	run_multiple_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i <= cmd->cmd_num)
	{
		if (cmd->precedence[i]->path)
		{
			if (cmd->precedence[i]->stdin_redirect)
			{
				if (!verify_fd(cmd->precedence[i]->stdin_redirect))
				{
					printf("No such file or directory\n");
					return ;
				}
			}
			run_cmd_test(cmd->precedence[i], &cmd->enviro, cmd->env);
		}
		else
		{
			printf("%s%s%s\n", RED_TEXT,
				"This command is not recognized on this shell: ",
				cmd->precedence[i]->cmd);
			return ;
		}
		i++;
	}
}
