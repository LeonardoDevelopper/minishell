/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:36 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/13 10:32:03 by lleodev          ###   ########.fr       */
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
	int	builtins;

	argc = argc;
	argv = argv;
	tmp = NULL;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!fill_env(&cmd->enviro, envp))
		return (1);
	ft_signal();
	while (1)
	{
		cmd->shell = display_shell(envp, tmp, &cmd->enviro);
		cmd->input = readline(cmd->shell);
		cmd->env = envp;
		if (cmd->input && *cmd->input)
		{
			cmd->cmd_splited = ft_split(cmd->input, ' ');
			builtins = check_builtins(cmd->cmd_splited, &cmd->enviro, envp);
			if (!builtins)
			{
				cmd->cmd_num = count_cmds_num(cmd->input);
				cmd->precedence = split_cmds(cmd->input, cmd->cmd_num);
				if (comd_exits(cmd))
					run_multiple_cmd(cmd);
				
			}
			add_history(cmd->input);
			free(cmd->input);
		}
		free(cmd->shell);
	}
	return (0);
}
