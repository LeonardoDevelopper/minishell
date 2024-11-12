/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:36 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/12 16:36:21 by lleodev          ###   ########.fr       */
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
			builtins = check_builtins(cmd->cmd_splited, &cmd->info, envp);
			if (!builtins)
			{
				cmd->full_path = cmd_exist(cmd->cmd_splited[0]);
				if (cmd->full_path)
				{
					int	p = 0;
					cmd->precedence = (t_prec **)malloc(sizeof(t_prec *) * (count_rows_del(cmd->input, '|') + 2));
					char	**commands = ft_split(cmd->input, '|');
					while (p <= count_rows_del(cmd->input, '|'))
					{
						cmd->precedence[p] = (t_prec *)malloc(sizeof(t_prec));
						char *str_trimmed = ft_strtrim(commands[p], " ");
						cmd->precedence[p]->cmd = str_trimmed;
						cmd->precedence[p]->redirect = verify_redirect_stdin(cmd->precedence[p]->cmd);
						char	*remove = remove_char(str_trimmed, '<');
						cmd->precedence[p]->full_path = cmd_exist(ft_split(remove, ' ')[0]);
						cmd->precedence[p]->num_args = count_rows_del(remove, ' ') + 1;
						cmd->precedence[p]->args = ft_split(remove, ' ');
						if (!cmd->precedence[p]->full_path)
							printf("This command is not recognized on this shell: %s", cmd_exist(ft_split(remove, ' ')[0]));
						p++;
					}
					int	i = 0;
					while (i <= count_rows_del(cmd->input, '|'))
					{
						cmd->precedence[i]->redirect = verify_redirect_stdin(cmd->precedence[i]->cmd);
						if (cmd->precedence[i]->redirect)
						{
							if (!verify_fd(cmd->precedence[i]->redirect))
								printf("No such file or directory\n");
							else
								redirect_stdin_test(cmd->precedence[i], envp);
						}
						else
							run_cmd_test(cmd->precedence[i], &cmd->info, envp);
						i++;
					}
					/*while (i < p)
					{
						printf("\nNum args: %d\nCmd : %s\nArgs: ", cmd->precedence[i]->num_args, cmd->precedence[i]->cmd);
						int	j = 0;
						while (cmd->precedence[i]->args[j])
							printf("%s, ", cmd->precedence[i]->args[j++]);
						if(cmd->precedence[i]->redirect)
						{
							int	r = 0;
							printf("\nRedirects: ");
							while (r < cmd->precedence[i]->redirect->count)
								printf("%d, ", cmd->precedence[i]->redirect->fd_list[r++]);
						}
						i++;
						printf("\n");
					}
					while (cmd->precedence[i])
					{
						printf("\n%s", cmd->precedence[i]->args[0]);
						i++;
					}*/
					
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
