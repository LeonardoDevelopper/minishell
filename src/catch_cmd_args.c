/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_cmd_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:59:27 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/31 16:23:21 by lleodev          ###   ########.fr       */
/*                                                                            */
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

int	ft_strlen_custom2(char *str)
{
	int	len;

	len = 0;
	while(str[len] && (str[len] == 32 || str[len] > 9 && str[len] <= 13))
		len++;
	while (str[len] && !(str[len] == 32 || str[len] > 9 && str[len] <= 13))
		len++;
	return (len);
}

char	**catch_cmd_args(char *cmd)
{
	int	argc;
	int	i;
	int	j;
	char	**args;
	char	**res;

	i = 0 ;
	argc = count_cmd_args(cmd);
	res = (char **)malloc(sizeof(char *) * (argc + 1));
	args = ft_split(cmd, ' ');
	while (args[i])
	{
		if (ft_strchr(args[i], '-'))
		{
			args[i] = (char *)malloc(sizeof(char ) * ft_strlen_custom2(cmd) + 1);
			args[i][ft_strlen_custom2(cmd)] = '\0';
			j = 0;
			while (args[i][j])
				res[i][j++] = cmd++;
			i++;
		}
		else
			i++;
	}
	printf("\n%s", res[0]);
	return (res);
}
