/* ************************************************************************** */
/*    */
/*        :::      ::::::::   */
/*   catch_cmd_args.c           :+:      :+:    :+:   */
/*    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>         +#+  +:+       +#+        */
/*+#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:59:27 by lleodev           #+#    #+# */
/*   Updated: 2024/11/01 18:27:32 by lleodev          ###   ########.fr       */
/*    */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmd_args(char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		if (cmd[i] == '-')
		{
			if (cmd[i + 1] == '-')
			{
				if (ft_isalpha(cmd[i + 2]))
				{
					count++;
					i += 2;
				}
			}
			else if (ft_isalpha(cmd[i + 1]))
			{
				count++;
				i += 1;
			}
		}
		else
			i++;
	}
	return (count);
}



char **catch_cmd_args(t_cmd *cmd)
{
	int		i;
	int		j;
	int		k;
	char	**args;
	char	**res;

	i = 0;
	k = 1;
	if (count_cmd_args(cmd->input) < 1)
		return (NULL);

	res = (char **)malloc(sizeof(char *) * (count_cmd_args(cmd->input) + 2));
	res[count_cmd_args(cmd->input) + 1] = NULL;
	args = ft_split(cmd->input, ' ');
	while (args[i])
	{
		if (i == 0)
		{
			j = 0;
			res[0] = (char *)malloc(sizeof(char) * (ft_strlen(args[0]) + 1));
			if (!res[0]) return NULL;

			while (args[0][j])
			{
				res[0][j] = args[0][j];
				j++;
			}
			res[0][j] = '\0';
		}
		else
		{
			if (ft_strchr(args[i], '-'))
			{
				j = 0;
				res[k] = (char *)malloc(sizeof(char) * (ft_strlen(args[i]) + 1));
				while (args[i][j])
				{
					res[k][j] = args[i][j];
					j++;
				}
				res[k][j] = '\0';
				k++;
			}
		}
		i++;
	}
	return (res);
}
