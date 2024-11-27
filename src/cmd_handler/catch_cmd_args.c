/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:19:21 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/27 11:42:52 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*catch_cmd_args(char *cmd)
{
	int	i;
	int	j;
	int	k;
	char	*args;
	char	**args_splited;

	i = 0;
	k = 0;
	args = (char *)malloc(sizeof(char ) * ft_strlen(cmd));
	args_splited = ft_split(cmd, ' ');
	while (args_splited[i])
	{
		if (ft_strcmp(args_splited[i], "<") || ft_strcmp(args_splited[i], ">")
			|| ft_strcmp(args_splited[i], ">>") || ft_strcmp(args_splited[i], "<<"))
			i += 2;
		else
		{
			j = 0;
			while (args_splited[i][j])
				args[k++] = args_splited[i][j++];
			args[k++] = ' ';
			i++;
			
		}
	}
	args[k] = '\0';
	return (args);
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