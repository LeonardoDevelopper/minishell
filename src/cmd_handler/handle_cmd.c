/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:06:32 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/11 15:54:37 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_cmd(t_cmd *cmd)
{
	char	*tmp;

	tmp = epur_str(cmd->input);
	free(cmd->input);
	cmd->input = (char *)malloc(sizeof(char ) * ft_strlen(tmp) + 1);
	ft_strcpy(cmd->input, tmp);
	free(tmp);
	if (ft_strlen(cmd->input) == 0)
		return ;
	if (ft_handle_quotes(cmd->input) && ft_handle_tokens(cmd->input))
	{
		cmd->cmd_num = count_cmds_num(cmd->input) + 1;
		cmd->precedence = split_cmds(cmd, cmd->input, cmd->cmd_num);
		if (cmd->precedence)
		{
			if (test_commands(cmd))
			{
				if (cmd->cmd_num > 1)
					run_multiple_cmd(cmd);
				else
					run_cmd(cmd, NULL, 0);
			}
			free_cmd(cmd);
		}
	}
}

void	handle_args(t_prec *prec)
{
	int		first;
	char	*args;
	char	*tmp;

	tmp = NULL;
	first = first_quote(prec->input);
	args = catch_cmd_args(prec->input, tmp, first);
	if (args)
	{
		prec->args = ft_split(args, ' ');
		fill_args(prec->args);
		free(args);
	}
}

void	handle_cmd_exist(t_cmd *cmd, t_prec *prec)
{
	char	**tmp;

	if (!prec->input)
		return ;
	tmp = ft_split(prec->input, ' ');
	prec->cmd = (char *)malloc(ft_strlen(tmp[0]) + 1);
	ft_strcpy(prec->cmd, tmp[0]);
	free_matrix(tmp);
	prec->path = cmd_exist(cmd, prec->cmd);
}
