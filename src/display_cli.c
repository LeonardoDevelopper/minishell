/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:43:12 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/14 16:43:14 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*display_shell(char *envp[], char **tmp_tmp, t_enviro **enviro)
{
	char	*user;
	char	*host;
	char	dir[1024];
	char	*tmp;
	char	*shell;

	user = (char *)run_cmd_catch_output("whoami", enviro, envp);
	user = remove_end_char(user);
	host = (char *)run_cmd_catch_output("hostname", enviro, envp);
	//host = replace_char(host, '\n', ' ');
	getcwd(dir, sizeof(dir));
	tmp_tmp = ft_split(host, '.');
	shell = SHELL_1;
	tmp = ft_strjoin(shell, user);
	shell = ft_strjoin(tmp, SHELL_2);
	free(tmp);
	tmp = ft_strjoin(shell, tmp_tmp[0]);
	free(shell);
	free_matrix(tmp_tmp);
	shell = ft_strjoin(tmp, SHELL_3);
	free(tmp);
	tmp_tmp = ft_split(dir, '/');
	tmp = ft_strjoin(shell, tmp_tmp[count_desk(dir) - 1]);
	free(shell);
	shell = ft_strjoin(tmp, SHELL_4);
	return (free(user), free(host),  shell);
}
