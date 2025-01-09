/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:36 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/09 10:29:37 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd	*cmd;
	char	**tmp;

	cmd = initialize_prompt(argc, argv, envp);
	ft_signal();
	while (1)
	{
		cmd->shell = display_shell(envp, tmp, &cmd->enviro);
		cmd->input = readline(cmd->shell);
		cmd->env = fill_max(&cmd->enviro);
		ft_ctrld(cmd->input, cmd->env);
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
	if (cmd->env)
		free_matrix(cmd->env);
	return (free_enviro_list(&cmd->enviro), 0);
}
