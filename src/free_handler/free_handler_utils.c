/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:14:28 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/09 11:00:45 by lleodev          ###   ########.fr       */
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
	free(trimmed_str);
	free(cmd->shell);
	free_matrix(cmd->env);
	free_enviro_list(&cmd->enviro);
	free(cmd);
}
