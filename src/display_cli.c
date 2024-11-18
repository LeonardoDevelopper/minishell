/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:43:12 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/16 19:35:01 by lleodev          ###   ########.fr       */
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

	user = getenv("USER");
	host = (char *)run_cmd_catch_output("hostname", enviro, envp);
	host = remove_char(host, '\n');
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
	tmp_tmp++;
	tmp_tmp++;
	tmp = ft_strjoin(shell, ft_strjoin_matrix(tmp_tmp, '/'));
	free(shell);
	shell = ft_strjoin(tmp, SHELL_4);
	return (free(host),  shell);
}
