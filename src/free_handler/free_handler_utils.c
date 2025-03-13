/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:14:28 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/15 10:41:54 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix != NULL)
	{
		while (matrix[i] != NULL)
		{
			free(matrix[i]);
			matrix[i++] = NULL;
		}
		free(matrix);
		matrix = NULL;
	}
}

void	free_left(char *trimmed_str, t_cmd *cmd)
{
	free(cmd->input);
	free(trimmed_str);
	free(cmd->shell);
	free(cmd->expanded_input);
	free_matrix(cmd->env);
	free_enviro_list(&cmd->enviro);
	free(cmd);
}

void	free_left2(char *trimmed_str, t_cmd *cmd)
{
	free(cmd->input);
	free(cmd->expanded_input);
	free(trimmed_str);
	free(cmd->shell);
	free_matrix(cmd->env);
}

void	free_pipe(int **pipe)
{
	int	i;

	i = 0;
	if (pipe != NULL)
	{
		while (pipe[i] != NULL)
		{
			free(pipe[i]);
			pipe[i++] = NULL;
		}
		free(pipe);
		pipe = NULL;
	}
}

void	free_two(char *tmp, char **tmp2)
{
	free(tmp);
	free_matrix(tmp2);
}
