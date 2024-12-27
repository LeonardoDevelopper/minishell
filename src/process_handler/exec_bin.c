/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:01:34 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/18 11:12:12 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*run_cmd_catch_output(char *cmd, char *env[])
{
	int			pipe_fd[2];
	char		**full_cmd;
	char		*full_path;
	char		*output;
	t_child_p	*child;

	full_cmd = ft_split(cmd, ' ');
	full_path = cmd_exist(NULL, full_cmd[0]);
	if (full_path)
	{
		pipe(pipe_fd);
		child = new_child_p(pipe_fd);
		if (child->pid == 0)
			run_child_p_test(full_path, full_cmd, child, env);
		close(((int *)child->pipe_fd)[1]);
		waitpid(child->pid, &child->status, 0);
		output = read_stdout_child(((int *)child->pipe_fd)[0]);
		free(child);
		free_matrix(full_cmd);
		free(full_path);
		return (output);
	}
	return (NULL);
}

void	execbin(t_cmd *cmd, t_prec *prec)
{
	execve(prec->path, prec->args, cmd->env);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	run_cmd(t_cmd *cmd, int **pipes, int i)
{
	if (!cmd->precedence[i]->builtins)
	{
		cmd->precedence[i]->child = new_child_p(NULL);
		if (cmd->precedence[i]->child->pid == 0)
		{
			change_input_output(i, cmd->cmd_num, pipes, cmd->precedence[i]);
			if (pipes != NULL)
				close_pipes(pipes, cmd->cmd_num);
			execbin(cmd, cmd->precedence[i]);
		}
		if (cmd->cmd_num == 1)
		{
			waitpid(cmd->precedence[i]->child->pid,
				&cmd->precedence[i]->child->status, 0);
			init_status(&cmd->enviro, cmd->precedence[i]->child->status);
		}
	}
	else
	{
		change_builtins_output(cmd, pipes, i);
		check_builtins(cmd->precedence[i], &cmd->enviro, cmd->env);
	}
}

void	run_multiple_cmd(t_cmd *cmd)
{
	int	**pipes;
	int	i;

	i = 0;
	pipes = NULL;
	pipes = create_pipes(cmd);
	while (i < cmd->cmd_num)
	{
		run_cmd(cmd, pipes, i);
		if (i > 0)
			close(pipes[i - 1][0]);
		if (i < (cmd->cmd_num - 1))
			close(pipes[i][1]);
		i++;
	}
	close_pipes(pipes, cmd->cmd_num);
	free_matrix(pipes);
	wait_p(cmd, cmd->cmd_num);
}
