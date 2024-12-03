/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:10:42 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/03 09:14:32 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds_num(char *input)
{
	return (count_rows_del(input, '|'));
}

t_prec	**split_cmds(char *input, int num_cmd)
{
	t_prec	**precedence;
	int		p;
	int		pipe[2];
	char	**commands;
	char	*str_trimmed;

	p = 0;
	precedence = (t_prec **)malloc(sizeof(t_prec *) * (num_cmd + 1));
	precedence[num_cmd] = NULL;
	commands = ft_split(input, '|');
	while (p < num_cmd)
	{
		precedence[p] = (t_prec *)malloc(sizeof(t_prec));
		str_trimmed = ft_strtrim(commands[p], " ");
		precedence[p]->input = str_trimmed;
		handle_stdin(precedence[p]);
		handle_cmd_exist(precedence[p]);
		handle_double_quotes(precedence[p]->input);
		handle_args(precedence[p]);
		handle_stdout(precedence[p]);
		free(str_trimmed);
		p++;
	}
	free_matrix(commands);
	return (precedence);
}
