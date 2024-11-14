/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_exist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:04:59 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/13 13:05:02 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	comd_exits(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i <= cmd->cmd_num)
	{
		if (!cmd->precedence[i]->path)
		{
			printf("%s%s%s\n", RED_TEXT, "This command is not recognized on this shell: ", cmd->precedence[i]->cmd);
			return (0);
		}
		i++;
	}
	return (1);
}
