/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:11:15 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/03 09:26:11 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    free_cmd(t_cmd *cmd)
{
    if (cmd)
    {
        free_prec(cmd->precedence);
        //if (cmd->input)
        //    free(cmd->input);
        //if (cmd->shell)
        //	free(cmd->shell);
        //free(cmd);
    }
}

void    free_prec(t_prec **prec)
{
	int	i;

	i = 0;
	while (prec[i])
	{
		if (prec[i]->stdin_redirect)
		{
			free(prec[i]->stdin_redirect->fd_list);
			free(prec[i]->stdin_redirect);
		}
		if (prec[i]->stdout_redirect)
		{
			free(prec[i]->stdout_redirect->fd_list);
			free(prec[i]->stdout_redirect);
		}
		if (prec[i]->path)
			free(prec[i]->path);
		if (prec[i]->args)
			free_matrix(prec[i]->args);
		if (prec[i]->child)
			free(prec[i]->child);
		if (prec[i]->cmd)
			free(prec[i]->cmd);
		i++;
	}
	free_matrix(prec);
}
