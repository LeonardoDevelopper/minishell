/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_exist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:04:59 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/21 14:59:17 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	test_commands(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->cmd_num)
	{
		if (cmd->precedence[i]->path)
		{
			if (cmd->precedence[i]->stdin_redirect)
			{
				if (!verify_fd(cmd->precedence[i]->stdin_redirect))
				{
					printf("No such file or directory\n");
					return (0);
				}
			}
		}
		else
		{
			printf("%s%s%s\n", RED_TEXT, CMD_NO_EXIST,
				cmd->precedence[i]->cmd);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_builtins(char **cmd)
{
	int	k;

	k = 0;
	if (!cmd || !cmd[k])
		return (0);

	char *clean_cmd = remove_char(cmd[k], '"');
	if (!clean_cmd)
		return (0);

	if (ft_strcmp(clean_cmd, "echo"))
		return (1);
	else if (ft_strcmp(clean_cmd, "cd"))
		return (1);
	else if (ft_strcmp(clean_cmd, "export"))
		return (1);
	else if (ft_strcmp(clean_cmd, "unset"))
		return (1);
	else if (ft_strcmp(clean_cmd, "pwd"))
		return (1);
	else if (ft_strcmp(clean_cmd, "env"))
		return (1);
	else if (ft_strcmp(clean_cmd, "exit"))
		return (1);
	else
		return (0);
}
