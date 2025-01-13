/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_redirect.c                                   :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:12:34 by aborges           #+#    #+#             */
/*   Updated: 2025/01/08 12:12:37 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	case_redirect(char **echo, char *value, int *var)
{
	if (echo[var[3]][var[4]] == '>')
	{
		var[2] = 1;
		var[3]++;
	}
	else if ((echo[var[3]][var[4]] == 34
		|| echo[var[3]][var[4]] == 39) && var[2] == 1)
	{
		var[1]++;
	}
	else if (var[1] != 1 && var[2] == 0)
	{
		value[var[0]] = echo[var[3]][var[4]];
		var[0]++;
	}
	var[4]++;
}

void	case_redirect_quots(char **echo, char *value, int *var)
{
	if ((echo[var[3]][var[4]] == 34
		|| echo[var[3]][var[4]] == 39) && var[2] == 1)
	{
		var[1]++;
	}
	else if (var[1] != 1 && var[2] == 0)
	{
		value[var[0]] = echo[var[3]][var[4]];
		var[0]++;
	}
	var[4]++;
}
