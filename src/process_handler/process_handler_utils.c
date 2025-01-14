/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_handler_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:07:39 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/14 08:30:06 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_p(t_cmd *cmd, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (!cmd->precedence[i]->builtins)
		{
			waitpid(cmd->precedence[i]->child->pid,
				&cmd->precedence[i]->child->status, 0);
		}
		i++;
	}
	if (!cmd->precedence[num - 1]->builtins)
		init_status(&cmd->enviro, cmd->precedence[num - 1]->child->status);
}

void	change_builtins_output(t_cmd *cmd, int **pipes, int i)
{
	if (pipes != NULL)
	{
		if (i > 0)
			cmd->precedence[i]->stdout = pipes[i - 1][0];
		if (i < (cmd->cmd_num - 1))
			cmd->precedence[i]->stdout = pipes[i][1];
	}
}

void	change_input_output(int i, int num, int **pipes, t_prec *prec)
{
	if (pipes != NULL)
	{
		if (i > 0)
			dup2(pipes[i - 1][0], STDIN_FILENO);
		if (i < (num - 1))
			dup2(pipes[i][1], STDOUT_FILENO);
	}
	if (prec->stdin_redirect)
		dup2(prec->stdin, STDIN_FILENO);
	if (prec->stdout_redirect)
		dup2(prec->stdout, STDOUT_FILENO);
}
