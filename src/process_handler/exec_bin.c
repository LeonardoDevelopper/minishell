/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:01:34 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/05 08:35:32 by lleodev          ###   ########.fr       */
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

void	run_cmd(t_cmd *cmd, t_prec *prec)
{
	if (prec->builtins)
		check_builtins(prec, &cmd->enviro, cmd->env);
	else
	{
		execve(prec->path,
			prec->args, cmd->env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	change_input_output(int i, int num, int **pipes, t_prec *prec)
{
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < num -1)
		dup2(pipes[i][1], STDOUT_FILENO);
	if (prec->stdin_redirect)
		dup2(prec->stdin, STDIN_FILENO);
	if (prec->stdout_redirect && !prec->builtins)
		dup2(prec->stdout, STDOUT_FILENO);
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
			change_input_output(i, cmd->cmd_num, pipes, cmd->precedence[i]);
			close_pipes(pipes, cmd->cmd_num);
			run_cmd(cmd, cmd->precedence[i]);
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