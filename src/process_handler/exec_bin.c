/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:01:34 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/13 11:45:03 by lleodev          ###   ########.fr       */
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
	full_path = cmd_exist(full_cmd[0]);
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

void	change_input_output(t_cmd *cmd, int **pipes, int i)
{
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < cmd->cmd_num -1)
		dup2(pipes[i][1], STDOUT_FILENO);
	if (cmd->precedence[i]->stdin_redirect)
		dup2(cmd->precedence[i]->stdin, STDIN_FILENO);
	if (cmd->precedence[i]->stdout_redirect)
		dup2(cmd->precedence[i]->stdout, STDOUT_FILENO);
}

void	run_cmd(t_cmd *cmd, int i)
{
	if (cmd->precedence[i]->builtins)
		check_builtins(cmd->precedence[i], &cmd->enviro, cmd->env);
	else
	{
		execve(cmd->precedence[i]->path,
			cmd->precedence[i]->args, cmd->env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	run_multiple_cmd(t_cmd *cmd)
{
	int			**pipes;
	int			i;

	pipes = create_pipes(cmd);
	i = 0;
	while (i < cmd->cmd_num)
	{
		cmd->precedence[i]->child = new_child_p(NULL);
		if (cmd->precedence[i]->child->pid == 0)
		{
			change_input_output(cmd, pipes, i);
			close_pipes(pipes, cmd->cmd_num);
			run_cmd(cmd, i);
		}
		if (cmd->precedence[i]->stdout_redirect)
			close(cmd->precedence[i]->stdout);
		i++;
	}
	close_pipes(pipes, cmd->cmd_num);
	wait_p(cmd->cmd_num);
}

void	wait_p(int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		wait(NULL);
		i++;
	}
}
