/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:58:00 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/10 13:05:25 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds_num(char *input)
{
	return (count_rows_del(input, '|'));
}

char	*ft_expand(t_cmd *cmd)
{
	char	**tmp2;

	tmp2 = handle_non_builtin1(cmd->input);
	free(cmd->input);
	cmd->input = ft_echo(tmp2, &cmd->enviro);
	free_matrix(tmp2);
	if (!ft_strlen(cmd->input))
		return (NULL);
	return (cmd->input);
}
