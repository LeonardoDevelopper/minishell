/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:44:50 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/06 08:04:50 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	**create_pipes(t_cmd *cmd)
{
	int	**pipes;
	int	i;
	int	num;

	i = 0;
	num = cmd->cmd_num;
	pipes = (int **)ft_calloc(sizeof(int *) * (num + 1), sizeof(int));
	while (i < num)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (pipe(pipes[i]) == -1)
			perror("pipe");
		i++;
	}
	return (pipes);
}

int	close_pipes(int **pipes, int num)
{
	int	i;

	i = 0;
	while (i < (num - 1))
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	return (1);
}
