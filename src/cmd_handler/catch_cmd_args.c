/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:19:21 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/11 13:24:54 by lleodev          ###   ########.fr       */
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
	in = 0;
	j = 0;
	res = (char *)malloc(sizeof(char ) * (ft_strlen(input) + 1));
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			if (in)
				in = 0;
			else
				in = 1;
			i++;
			continue ;
		}
		if (in)
		{
			if (input[i] == 32 || input[i] <= 13)
				res[j] = '\\';
			else
				res[j] = input[i];
			j++;
		}
		else
			res[j++] = input[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}

//BUG getting the argumments
char	*catch_cmd_args(char *cmd)
{
int		i;
	int		j;
	int		k;
	int		quant;
	char	*args;
	char	**args_sp;
	char	*tmp;

	i = 0;
	k = 0;
	quant = 0;
	tmp = handle_between_quotes(cmd);
	args = (char *)malloc(sizeof(char ) * 1024);
	args_sp = ft_split(tmp, ' ');
	while (args_sp[i])
	{
		if (ft_strcmp(args_sp[i], "<") || ft_strcmp(args_sp[i], ">")
			|| ft_strcmp(args_sp[i], ">>") || ft_strcmp(args_sp[i], "<<"))
			i += 2; 
		else
		{
			j = 0;
			while (args_sp[i][j])
				args[k++] = args_sp[i][j++];
			args[k++] = ' ';
			i++;
		}
	}
	return (args[k] = '\0', free_matrix(args_sp), args);
}

void	fill_args(char **input)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (input[i])
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
		i++;
	}
	return (input);
}

int	count_char(char *str, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

/*

char	*remove_char(char *str, char c)
{
	int	i;
	int	j;
	int	counter;
	char	*new;

	i = 0;
	j = 0;
	counter = count_char(str, c);
	if (!counter)
		return (str);
	new = (char *)malloc(sizeof(char ) * ((ft_strlen(str) - counter) + 1));
	while (str[i])
	{
		if (str[i] != c)
			new[j++] = str[i++];
		else
			i++;
	}
	new[j] = '\0';
	return (new);
}
*/