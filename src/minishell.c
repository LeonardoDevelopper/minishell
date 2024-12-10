/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:36 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/07 11:26:09 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_desk(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '/')
			count++;
		i++;
	}
	return (count);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;
	char	**tmp;

	argc = argc;
	argv = argv;
	tmp = NULL;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!fill_env(&cmd->enviro, envp))
		return (1);
	//ft_signal();
	cmd->shell = display_shell(envp, tmp, envp);
	while (1)
	{
		cmd->input = readline(cmd->shell);
		cmd->env = envp;
		ft_ctrld(cmd->input);
		if (cmd->input && *cmd->input)
		{
			handle_exit(cmd);
			handle_cmd(cmd);
			add_history(cmd->input);
			free(cmd->input);
		}
	}
	return (0);
}
