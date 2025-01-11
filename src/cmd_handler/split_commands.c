/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:10:42 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/11 16:02:24 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_tokens(char *input, int first)
{
	int		i;
	int		k;
	int		in;
	int		j;
	char    *res;

	i = 0;
	k = 0;
	in = 0;
	char	*rdin = "rdin";
	char	*rdout = "redout";
	char    *pipe = "pipe";
	res = (char *)malloc(sizeof(char ) * 1024);
	while (input[i])
	{
		j = 0;
		if (first && (input[i] == first))
		{
			in++;
			res[k++] = input[i];
			i++;
			continue ;
		}
		if (in == 1)
		{
			if (input[i] == '<')
			{
				while (rdin[j])
				{
					res[k] = rdin[j];
					k++;
					j++;
				}
			}
			else if (input[i] == '>')
			{
				while (rdout[j])
				{
					res[k] = rdout[j];
					k++;
					j++;
				}
			}
			else if (input[i] == '|')
			{
				while (pipe[j])
				{
					res[k] = pipe[j];
					k++;
					j++;
				}
			}
			else
			{
				res[k++] = input[i];
			}
		}
		else
		{
			if (in > 1)
			{
				in = 0;
			}
			res[k++] = input[i];
		}
		i++;
	}
	res[k] = '\0';
	return (res);
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
		handle_args(precedence[p], cmd->enviro);
		handle_stdout(precedence[p]);
		p++;
	}
	free_matrix(commands);
	return (precedence);
}
