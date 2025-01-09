/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:10:42 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/09 12:17:10 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds_num(char *input)
{
	return (count_rows_del(input, '|'));
}

t_prec	**split_cmds(t_cmd *cmd, char *input, int num_cmd)
{
	t_prec	**precedence;
	int		p;
	char	**commands;

	p = 0;
	precedence = (t_prec **)malloc(sizeof(t_prec *) * (num_cmd + 1));
	precedence[num_cmd] = NULL;
	commands = ft_split(input, '|');
	while (p < num_cmd)
	{
		precedence[p] = initialize_prec();
		precedence[p]->input = ft_strtrim(commands[p], " ");
		handle_stdin(precedence[p]);
		handle_cmd_exist(cmd, precedence[p]);
		handle_args(precedence[p]);
		handle_stdout(precedence[p]);
		p++;
	}
	free_matrix(commands);
	return (precedence);
}
