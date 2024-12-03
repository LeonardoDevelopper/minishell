/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:44:50 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/03 09:16:26 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**create_pipes(t_cmd *cmd)
{
	int	**pipes;
	int	i;
    int num;

	i = 0;
    num = cmd->cmd_num - 1;
	pipes = (int **)malloc(sizeof(int *) * num);
    while (i < num)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (pipe(pipes[i]) == -1)
			perror("pipe");
		i++;
	}
	return (pipes);
}

int close_pipes(int **pipes, int pipe_num)
{
	int	i;

	i = 0;
	while (i < pipe_num - 1)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
	return (1);
}
