/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:06:32 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/02 13:08:51 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    handle_cmd(t_cmd *cmd)
{
    if (ft_handle_tokens(cmd->input) && ft_handle_quotes(cmd->input))
	{
        cmd->cmd_num = count_cmds_num(cmd->input) + 1;
        cmd->precedence = split_cmds(cmd->input, cmd->cmd_num);
	    //print_args(cmd);
        if (cmd->precedence)
        {
            if (test_commands(cmd))
                run_multiple_cmd(cmd);
        }
	}
}