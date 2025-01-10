/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:58:00 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/10 11:03:04 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds_num(char *input)
{
	return (count_rows_del(input, '|'));
}

int	ft_expand(t_cmd *cmd)
{
	char	*tmp1;
	char	**tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	tmp1 = tmp1;
	tmp2 = tmp2;
	printf("command expanded: %s\n", cmd->input);
	return (1);
}