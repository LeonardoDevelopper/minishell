/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:06:32 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/09 11:44:53 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_cmd(t_cmd *cmd)
{
	if (ft_handle_quotes(cmd->input) && ft_handle_tokens(cmd->input))
	{
		cmd->cmd_num = count_cmds_num(cmd->input) + 1;
		cmd->precedence = split_cmds(cmd->input, cmd->cmd_num);
		if (cmd->precedence)
		{
			//print_args(cmd);
			if (test_commands(cmd))
				run_multiple_cmd(cmd);
			free_cmd(cmd);
		}
	}
}

void	handle_args(t_prec *prec)
{
	char	*args;

	args = catch_cmd_args(prec->input);
	prec->args = ft_split(args, ' ');
	free(args);
}

void	handle_cmd_exist(t_prec *prec)
{
	char	**tmp;

	tmp = ft_split(prec->input, ' ');
	prec->cmd = (char *)malloc(ft_strlen(tmp[0]) + 1);
	ft_strcpy(prec->cmd, tmp[0]);
	free_matrix(tmp);
	prec->path = cmd_exist(prec->cmd);
}
