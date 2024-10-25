/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:55:36 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/14 08:13:53 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_desk(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '/')
			count++;
		i++;
	}
	return (count);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;
	char	*shell;
	char	*output;
	char	**tmp;;
	char	*stdin_file;
	t_info	*info;

	argc = argc;
	argv = argv;
	tmp = NULL;
	info = NULL;
	if (!fill_env(&info, envp))
		return (1);
	ft_signal();
	while (1)
	{
		shell = display_shell(envp, tmp, &info);
		input = readline(shell);
		if (input && *input)
		{
			stdin_file = redirect_stdin(input);
			if (stdin_file)
				printf("%s", stdin_file);
			else
				run_cmd(input, &info, envp);
			add_history(input);
			free(input);
			//if (output);
			//	free(output);
		}
		free(shell);
	}
	if(input)
		free(input);
	return (0);
}
