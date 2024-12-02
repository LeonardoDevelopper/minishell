/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:56:56 by aborges           #+#    #+#             */
/*   Updated: 2024/12/02 10:56:58 by aborges          ###   ########.fr       */
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
		if (ft_searstr(list[i], "?=") == NULL)
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
