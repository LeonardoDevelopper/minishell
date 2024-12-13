/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:43:12 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/13 11:45:34 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*display_shell(char *envp[], char **tmp_tmp, char **env)
{
	char	*user;
	char	*host;
	char	dir[1024];
	char	*tmp[8];
	char	*shell;

	user = getenv("USER");
	host = (char *)run_cmd_catch_output("hostname", envp);
	host = remove_char(host, '\n');
	getcwd(dir, sizeof(dir));
	tmp_tmp = ft_split(host, '.');
	free(host);
	host = malloc(sizeof(char ) * (ft_strlen(tmp_tmp[0]) + 1));
	ft_strcpy(host, tmp_tmp[0]);
	tmp[0] = SHELL_1;
	tmp[1] = user;
	tmp[2] = SHELL_2;
	tmp[3] = host;
	tmp[4] = SHELL_3;
	tmp[5] = dir;
	tmp[6] = SHELL_4;
	tmp[7] = NULL;
	free_matrix(tmp_tmp);
	shell = ft_strjoin_matrix(tmp, ' ');
	return (free(host), shell);
}
