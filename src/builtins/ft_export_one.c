/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:38:52 by aborges           #+#    #+#             */
/*   Updated: 2025/01/08 12:39:02 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_export_loop(char **export, int ac, t_enviro **enviro)
{
	int	j;

	j = 1;
	while (j < ac)
	{
		export_check(export, ac, enviro, j);
		j++;
	}
}
