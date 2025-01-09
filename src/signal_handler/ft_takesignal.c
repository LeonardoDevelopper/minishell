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
	char		*shell;
	char		**tmp;
	extern char	**environ;

	tmp = NULL;
	if (signal_value == SIGINT)
	{
		shell = display_shell2(environ, tmp);
		rl_replace_line("", 0);
		printf("\n%s\n", shell);
		rl_on_new_line();
		rl_redisplay();
		free(shell);
	}
}

void	ft_signal(void)
{
	signal(SIGINT, ft_signal_value);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_ctrld(char *input, char **mat_env)
{
	if (!input)
	{
		free_matrix(mat_env);
		exit(0);
	}
}
