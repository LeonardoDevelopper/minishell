/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:36 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/14 08:13:53 by lleodev          ###   ########.fr       */
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
	char	**tmp;;
	t_redirect	*redirect;
	t_info	*info;

	argc = argc;
	argv = argv;
	tmp = NULL;
	info = NULL;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!fill_env(&info, envp))
		return (1);
	ft_signal();
	while (1)
	{
		cmd->shell = display_shell(envp, tmp, &info);
		cmd->input = readline(cmd->shell);
		if (cmd->input && *cmd->input)
		{
			catch_cmd_args(cmd->input);
		/*
			cmd->redirect = verify_redirect_stdin(cmd->input);
			if (cmd->redirect)
			{
				if (!verify_fd(cmd->redirect))
					printf("no such file or directory\n");
				else
					redirect_stdin(cmd->redirect, cmd->input, envp);
			}
			else
				run_cmd(input, &info, envp);
			add_history(input);
			free(input);
		*/
		}
		free(cmd->shell);
	}
	return (0);
}
