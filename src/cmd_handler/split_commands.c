/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:10:42 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/21 15:00:13 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_prec	**split_cmds(char *input, int num_cmd)
{
	t_prec	**precedence;
	char	**aux;
	char	*stdout;
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
			//	if (handle_heredoc())
			//		precedence[p]->stdin = STDIN_FILENO;
			//	else
					precedence[p]->stdin = precedence[p]->stdin_redirect->fd_list[precedence[p]->stdin_redirect->count - 1];
		}
		else
			precedence[p]->stdin = STDIN_FILENO;
		//char	*str_args = remove_str(precedence[p]->input);
		char	*remove = remove_char(str_trimmed, '<');
		//printf("\nARGS : %s\n", str_args);
		precedence[p]->cmd = ft_split(remove, ' ')[0];
		precedence[p]->path = cmd_exist(precedence[p]->cmd);
		aux = ft_split(remove, ' ');
		stdout = ft_strjoin_matrix(aux, ' ');
		precedence[p]->stdout_redirect = verify_redirect_stdout(stdout);
		if (precedence[p]->stdout_redirect)
		{
			char	*remove2 = remove_char(stdout, '>');
			precedence[p]->args = ft_split(remove2, ' ');
			precedence[p]->num_args = count_rows_splited(precedence[p]->args);
			free(precedence[p]->args[precedence[p]->num_args -1]);
			precedence[p]->args[precedence[p]->num_args -1] = NULL;
			precedence[p]->stdout = precedence[p]->stdout_redirect->fd_list[0];
		}
		else
		{
			precedence[p]->args = ft_split(stdout, ' ');
			precedence[p]->num_args = count_rows_splited(precedence[p]->args);
			precedence[p]->stdout = STDOUT_FILENO;
		}
		p++;
	}
	return (precedence);
}

int	count_cmds_num(char *input)
{
	return (count_rows_del(input, '|'));
}
