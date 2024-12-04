/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:19:21 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/04 16:33:41 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*catch_cmd_args(char *cmd)
{
	int		i;
	int		j;
	int		k;
	char	*args;
	char	**args_sp;

	i = 0;
	k = 0;
	args = (char *)malloc(sizeof(char ) * 1024);
	args_sp = ft_split(cmd, ' ');
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