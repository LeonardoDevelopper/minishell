/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:56:56 by aborges           #+#    #+#             */
/*   Updated: 2025/01/09 12:26:13 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_chech_builtin(t_prec *prec)
{
	ft_putstr_fd("Invalid arg! ", prec->stdout);
	ft_putstr_fd("ft_check_cots(cmd)", prec->stdout);
	ft_putstr_fd("\n", prec->stdout);
}

void	print_env(char **env, int fd)
{
	ft_putstr_fd("env: ", fd);
	ft_putstr_fd(env[1], fd);
	ft_putstr_fd(": No such file or directory", fd);
	ft_putstr_fd("\n", fd);
}

void	print_list_env(char **list, int fd, int i)
{
	while (i >= 0)
	{
		if (ft_searstr(list[i], "?=") == 0)
		{
			ft_putstr_fd(list[i], fd);
			ft_putstr_fd("\n", fd);
		}
		i--;
	}
}

void	print_export(char **list, int fd, int i)
{
	ft_putstr_fd("declare -x ", fd);
	ft_putstr_fd(list[i], fd);
	ft_putstr_fd("\n", fd);
}

void	fill_str(char *str)
{
	str[0] = '~';
	str[1] = '!';
	str[2] = '@';
	str[3] = '#';
	str[4] = '$';
	str[5] = '%';
	str[6] = '^';
	str[7] = '&';
	str[8] = '*';
	str[9] = '(';
	str[10] = ')';
	str[11] = '+';
	str[12] = '-';
	str[13] = '=';
	str[14] = '\0';
}
