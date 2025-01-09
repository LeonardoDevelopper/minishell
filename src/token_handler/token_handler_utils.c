/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:51:54 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/09 12:23:01 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_space(char *cmd, int i)
{
	while ((cmd[i] && cmd[i] == 32) || (cmd[i] > 9 && cmd[i] <= 13))
		i++;
	return (i);
}

int	check_cmd_token_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == '|' || str[i - 1] == '<' || str[i - 1] == '>')
		return (1);
	return (0);
}

int	dup_tokens_followed(char *n, int i, int len)
{
	if ((i + 1) < len)
	{
		if ((n[i] == '<' && (n[i + 1] == '>' || n[i + 1] == '|'))
			|| (n[i] == '>' && (n[i + 1] == '<' || n[i + 1] == '|')))
			return (free(n), 1);
		if (n[i] == '|' && (n[i + 1] == '|'
				|| n[i + 1] == '>' || n[i + 1] == '<'))
			return (free(n), 1);
	}
	if ((i + 2) < len)
	{
		if ((n[i] == '<' || n[i] == '>' || n[i] == '|')
			&& (n[i + 2] == '<' || n[i + 2] == '>' || n[i + 2] == '|'))
			return (free(n), 1);
	}
	return (0);
}
