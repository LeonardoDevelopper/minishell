/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_exist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:04:59 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/10 15:12:45 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	test_commands(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->cmd_num)
	{
		if (is_builtins(&cmd->precedence[i]) || cmd->precedence[i]->path)
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

int	is_builtins(t_prec **prec)
{
	t_prec	*tmp;

	tmp = *prec;
	tmp->builtins = 0;
	if (!tmp->cmd)
		return (0);
	if (ft_strcmp(tmp->cmd, "echo"))
		return (1);
	else if (ft_strcmp(tmp->cmd, "cd"))
		return (1);
	else if (ft_strcmp(tmp->cmd, "export"))
		return (1);
	else if (ft_strcmp(tmp->cmd, "unset"))
		return (1);
	else if (ft_strcmp(tmp->cmd, "pwd"))
		return (1);
	else if (ft_strcmp(tmp->cmd, "env"))
		return (1);
	else if (ft_strcmp(tmp->cmd, "exit"))
		return (1);
	return (0);
}

int	is_builtins_new(char *cmd)
{
	char	**tmp;

	tmp = ft_split(cmd, 32);
	if (!tmp)
		return (0);
	if (ft_strcmp(tmp[0], "echo"))
		return (1);
	else if (ft_strcmp(tmp[0], "cd"))
		return (1);
	else if (ft_strcmp(tmp[0], "export"))
		return (1);
	else if (ft_strcmp(tmp[0], "unset"))
		return (1);
	else if (ft_strcmp(tmp[0], "pwd"))
		return (1);
	else if (ft_strcmp(tmp[0], "env"))
		return (1);
	else if (ft_strcmp(tmp[0], "exit"))
		return (1);
	return (0);
}
