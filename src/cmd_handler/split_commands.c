/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:10:42 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/14 08:50:16 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cpy_tokens(char *res, const char *src, int k)
{
	int	j;

	j = 0;
	while (src[j])
	{
		res[k] = src[j];
		k++;
		j++;
	}
	return (k);
}

int	inside(int in)
{
	if (in > 1)
		in = 0;
	return (in);
}

int	switch_token(char *input, char *res, int i, int k)
{
	if (input[i] == '<')
		k = cpy_tokens(res, "rdin", k);
	else if (input[i] == '>')
		k = cpy_tokens(res, "rdout", k);
	else if (input[i] == '|')
		k = cpy_tokens(res, "pipe", k);
	else if (input[i] == ';')
		k = cpy_tokens(res, "scolon", k);
	else if (input[i] == '?')
		k = cpy_tokens(res, "qmark", k);
	else if (input[i] == '&')
		k = cpy_tokens(res, "eco", k);
	else
		res[k++] = input[i];
	return (k);
}

char	*expand_tokens(char *input, int first, int in)
{
	int		i;
	int		k;
	char	*res;

	i = 0;
	k = 0;
	res = (char *)malloc(sizeof(char) * 1024);
	while (input[i])
	{
		if (first && input[i] == first)
		{
			in++;
			res[k++] = input[i++];
			continue ;
		}
		if (in == 1)
			k = switch_token(input, res, i, k);
		else
		{
			in = inside(in);
			res[k++] = input[i];
		}
		i++;
	}
	return (res[k] = '\0', res);
}

t_prec	**split_cmds(t_cmd *cmd, int num_cmd)
{
	t_prec	**precedence;
	int		p;
	char	**commands;

	p = 0;
	precedence = (t_prec **)malloc(sizeof(t_prec *) * (num_cmd + 1));
	precedence[num_cmd] = NULL;
	commands = ft_split(cmd->expanded_input, '|');
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
