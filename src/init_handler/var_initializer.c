/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:11:37 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/14 09:52:05 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize_cmd(t_cmd *cmd)
{
	cmd->precedence = NULL;
	cmd->enviro = NULL;
}

t_prec	*initialize_prec(void)
{
	t_prec	*prec;

	prec = (t_prec *)malloc(sizeof(t_prec));
	prec->num_args = 0;
	prec->path = NULL;
	prec->input = NULL;
	prec->cmd = NULL;
	prec->args = NULL;
	prec->stdin_redirect = NULL;
	prec->stdout_redirect = NULL;
	prec->child = NULL;
	prec->builtins = 0;
	prec->stdout = 1;
	prec->stdin = 0;
	return (prec);
}

t_redirect	*initialize_redirect(void)
{
	t_redirect	*redirect;

	redirect = (t_redirect *)malloc(sizeof(t_redirect));
	redirect->count = 0;
	redirect->fd_list = NULL;
	return (redirect);
}

t_cmd	*initialize_prompt(int argc, char *argv[], char *envp[])
{
	t_cmd	*prompt;

	argc = argc;
	argv = argv;
	prompt = (t_cmd *)malloc(sizeof(t_cmd));
	prompt->expanded_input = NULL;
	fill_env(&prompt->enviro, envp);
	return (prompt);
}
