/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:36 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/06 11:24:06 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;
	char	**tmp;

	argc = argc;
	argv = argv;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	fill_env(&cmd->enviro, envp);
	ft_signal();
	while (1)
	{
		cmd->shell = display_shell(envp, tmp, &cmd->enviro);
		cmd->input = readline(cmd->shell);
		cmd->env = fill_max(&cmd->enviro);
		ft_ctrld(cmd->input);
		if (cmd->input && *cmd->input)
		{
			if (!handle_exit(cmd))
				continue ;
			handle_cmd(cmd);
			if (ft_strlen(cmd->input) > 0)
				add_history(cmd->input);
			free(cmd->input);
		}
		free(cmd->shell);
	}
	return (free_enviro_list(&cmd->enviro), 0);
}
