/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:36 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/01 18:17:46 by lleodev          ###   ########.fr       */
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
	if (!fill_env(&cmd->info, envp))
		return (1);
	ft_signal();
	while (1)
	{
		cmd->shell = display_shell(envp, tmp, &cmd->info);
		cmd->input = readline(cmd->shell);
		if (cmd->input && *cmd->input)
		{
			cmd->cmd_splited = ft_split(cmd->input, ' ');
			builtins = check_builtins(cmd->cmd_splited, cmd->info, envp);
			if (!builtins)
			{
				cmd->full_path = cmd_exist(cmd->cmd_splited[0]);
				if (cmd->full_path)
				{
					cmd->precedence = (t_prec **)malloc(sizeof(t_proc *) * count_rows_del(cmd->input, '|') + 1);
					cmd->precedence[count_rows_del(cmd->input)] = NULL;
					while (cmd->precedence[p])
					{
						cmd->precedence[p]->args = ft_split(cmd->input, '|');
					}
					int	i = 0;
					while (cmd->precedence[i])
					{
						cmd->args = ft_split(cmd->precedence[i], ' ');
						cmd->redirect = verify_redirect_stdin(cmd->precedence[i]);
						if (cmd->redirect)
						{
							if (!verify_fd(cmd->redirect))
								printf("no such file or directory\n");
							else
								redirect_stdin(cmd, envp);
						}
						else
							run_cmd(cmd, envp);
						i++;
					}
					add_history(cmd->input);
					free(cmd->input);
				}
				else
					printf("%s%s%s\n", RED_TEXT, "this command is not recognized on this shell: ", cmd->cmd_splited[0]);
			}
		}
		free(cmd->shell);
	}
	return (0);
}
