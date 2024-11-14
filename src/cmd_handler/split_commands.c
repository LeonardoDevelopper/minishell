/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:10:42 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/13 12:10:45 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_prec	**split_cmds(char *input, int num_cmd)
{
	t_prec	**precedence;
	int		p;

	p = 0;
	precedence = (t_prec **)malloc(sizeof(t_prec *) * (num_cmd + 2));
	char	**commands = ft_split(input, '|');
	while (p <= num_cmd)
	{
		precedence[p] = (t_prec *)malloc(sizeof(t_prec));
		char *str_trimmed = ft_strtrim(commands[p], " ");
		precedence[p]->input = str_trimmed;
		precedence[p]->redirect = verify_redirect_stdin(precedence[p]->input);
		char	*remove = remove_char(str_trimmed, '<');
		precedence[p]->cmd = ft_split(remove, ' ')[0];
		precedence[p]->path = cmd_exist(precedence[p]->cmd);
		precedence[p]->args = ft_split(remove, ' ');
		precedence[p]->num_args = count_rows_splited(precedence[p]->args);
		p++;
	}
	return (precedence);
}

int	count_cmds_num(char *input)
{
	return (count_rows_del(input, '|'));
}
