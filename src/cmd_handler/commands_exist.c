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
