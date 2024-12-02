/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:10:42 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/02 13:38:05 by lleodev          ###   ########.fr       */
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

	p = 0;
	precedence = (t_prec **)malloc(sizeof(t_prec *) * (num_cmd + 1));
	precedence[num_cmd] = NULL;
	char	**commands = ft_split(input, '|');
	while (p < num_cmd)
	{
		precedence[p] = (t_prec *)malloc(sizeof(t_prec));
		char *str_trimmed = ft_strtrim(commands[p], " ");
		precedence[p]->input = str_trimmed;
		precedence[p]->stdin_redirect = verify_redirect_stdin(precedence[p]->input);
		if (precedence[p]->stdin_redirect)
		{
			if (verify_heredoc(precedence[p]->input) > 0)
			{
				precedence[p]->stdin_redirect->fd_list[precedence[p]->stdin_redirect->count - 1] = handle_heredoc(ft_strtrim(ft_split(precedence[p]->input, ' ')[2], " "));
				precedence[p]->stdin = precedence[p]->stdin_redirect->fd_list[precedence[p]->stdin_redirect->count - 1];
			}
			else if (verify_heredoc(precedence[p]->input) < 0)
				return (printf("error: Invalid token\n"), NULL);
			else if (verify_heredoc(precedence[p]->input) == 0)
				precedence[p]->stdin = precedence[p]->stdin_redirect->fd_list[precedence[p]->stdin_redirect->count - 1];
		}
		else
			precedence[p]->stdin = STDIN_FILENO;
		precedence[p]->cmd = ft_split(str_trimmed, ' ')[0];
		precedence[p]->path = cmd_exist(precedence[p]->cmd);
		precedence[p]->stdout_redirect = verify_redirect_stdout(str_trimmed);
		handle_double_quotes(precedence[p]->input);
		char	*args = catch_cmd_args(precedence[p]->input);
		precedence[p]->args = ft_split(args, ' ');
		precedence[p]->num_args = count_rows_splited(precedence[p]->args);
		if (precedence[p]->stdout_redirect)
			precedence[p]->stdout = precedence[p]->stdout_redirect->fd_list[0];
		else
			precedence[p]->stdout = STDOUT_FILENO;
		p++;
	}
	return (precedence);
}
