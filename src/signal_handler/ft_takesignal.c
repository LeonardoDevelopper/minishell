/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takesignal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:48:25 by aborges           #+#    #+#             */
/*   Updated: 2024/10/08 08:48:28 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signal_value(int signal_value)
{
	if (signal_value == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_signal(void)
{
	signal(SIGINT, ft_signal_value);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_ctrld(char *input)
{
	if (!input)
		exit(0);
}
