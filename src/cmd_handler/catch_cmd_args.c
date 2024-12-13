/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:19:21 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/13 12:55:46 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_between_quotes(char *input)
{
	int		i;
	int		j;
	int		in;
	char	*res;

	i = 0;
	j = 0;
	in = 0;
	res = (char *)malloc(sizeof(char ) * (ft_strlen(input) + 1));
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			in = in_quotes(in);
			i++;
			continue ;
		}
		if (in)
			replace_in_quotes(res, input, j++, i);
		else
			res[j++] = input[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	*catch_cmd_args(char *cmd)
{
	int		i;
	int		k;
	char	**sp;
	char	*tmp;
	char	*args;

	i = 0;
	k = 0;
	tmp = handle_between_quotes(cmd);
	sp = ft_split(tmp, ' ');
	free(tmp);
	args = (char *)malloc(sizeof(char ) * 1024);
	while (sp[i])
	{
		if (ft_strcmp(sp[i], "<") || ft_strcmp(sp[i], ">")
			|| ft_strcmp(sp[i], ">>") || ft_strcmp(sp[i], "<<"))
			i += 2;
		else
		{
			int j = 0;
			while (sp[i][j])
				args[k++] = sp[i][j++];
			args[k++] = ' ';
			i++;
		}
	}
	return (args[k] = '\0', free_matrix(sp), args);
}

void	fill_args(char **input)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (input[++i])
	{
		if (ft_findchar(input[i], '\\'))
		{
			j = 0;
			tmp = (char *)malloc(sizeof(char ) * (ft_strlen(input[i]) + 1));
			while (input[i][j])
			{
				if (input[i][j] == '\\')
					tmp[j] = ' ';
				else
					tmp[j] = input[i][j];
				j++;
			}
			tmp[j] = '\0';
			free(input[i]);
			input[i] = tmp;
		}
	}
	return (input);
}
