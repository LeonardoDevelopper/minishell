/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:23:10 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/13 12:23:12 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_args(t_cmd *cmd)
{
	int	p = count_rows_splited(cmd->precedence);
	int	i;

	i = 0;
	while (i < p)
	{
		printf("\nInput : %s\nPath: %s\nNum args: %d\nArgs: ",
			cmd->precedence[i]->input, cmd->precedence[i]->path,
			cmd->precedence[i]->num_args);
		int	j = 0;
		while (cmd->precedence[i]->args[j])
			printf("%s, ", cmd->precedence[i]->args[j++]);
			if(cmd->precedence[i]->stdin_redirect)
			{
				int	r = 0;
				printf("\nRedirects: \n");
				printf("\tstdin: ");
				while (r < cmd->precedence[i]->stdin_redirect->count)
					printf("%d, ", cmd->precedence[i]->stdin_redirect->fd_list[r++]);
				printf("\tstdout: ");
			}
			i++;
			printf("\n");
	}
}
