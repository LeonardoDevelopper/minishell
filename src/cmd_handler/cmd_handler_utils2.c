/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:58:00 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/13 11:49:34 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds_num(char *input)
{
	return (count_rows_del(input, '|'));
}

void	ft_expand(t_cmd *cmd)
{
	char		*tmp;
	char		*tmp2;
	char		**tmptmp;
	int			first;
	int			in;

	in = 0;
	first = first_quote(cmd->input);
	tmp = expand_tokens(cmd->input, first, in);
	tmptmp = ft_split(tmp, ' ');
	tmp2 = ft_echo_quots(tmptmp, &cmd->enviro);
	if (tmp2)
	{
		cmd->expanded_input
			= (char *)malloc(sizeof(char) * (ft_strlen(tmp2) + 1));
		ft_strcpy(cmd->expanded_input, tmp2);
	}
	else
	{
		cmd->expanded_input
			= (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1));
		ft_strcpy(cmd->expanded_input, tmp);
	}
	free(tmp);
	free_matrix(tmptmp);
}

char	*desk_to_space(char *input)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(input) + 1));
	res[ft_strlen(input)] = '\0';
	while (input[i])
	{
		if (input[i] == '\\')
			res[i] = ' ';
		else
			res[i] = input[i];
		i++;
	}
	return (res);
}
