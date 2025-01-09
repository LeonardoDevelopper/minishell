/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_exist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:04:59 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/10 15:12:45 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**prepare_echo_args(t_cmd *cmd, int i)
{
	char	**mat;

	mat = malloc(sizeof(char *) * 3);
	if (!mat)
		return (NULL);
	mat[0] = strdup("echo");
	mat[1] = strdup(cmd->precedence[i]->cmd);
	mat[2] = NULL;
	if (!mat[0] || !mat[1])
	{
		free(mat[0]);
		free(mat[1]);
		free(mat);
		return (NULL);
	}
	return (mat);
}

int	handle_non_builtin(t_cmd *cmd, int i)
{
	char	**mat;

	printf("%s%s%s", GREEN_TEXT, CMD_NO_EXIST, RESET);
	mat = prepare_echo_args(cmd, i);
	if (!mat)
		return (0);
	printf("%s", ft_echo(mat, &cmd->enviro));
	free(mat[0]);
	free(mat[1]);
	free(mat);
	return (0);
}

int	handle_redirects(t_cmd *cmd, int i)
{
	if (cmd->precedence[i]->stdin_redirect)
	{
		if (!verify_fd(cmd->precedence[i]->stdin_redirect))
		{
			printf("No such file or directory\n");
			return (0);
		}
	}
	return (1);
}

int	test_commands(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->cmd_num)
	{
		if (is_builtins(&cmd->precedence[i]) || cmd->precedence[i]->path)
		{
			if (!handle_redirects(cmd, i))
				return (0);
		}
		else
			return (handle_non_builtin(cmd, i));
		i++;
	}
	return (1);
}

int	is_builtins(t_prec **prec)
{
	t_prec	*tmp;

	tmp = *prec;
	tmp->builtins = 0;
	if (!tmp->cmd)
		tmp->builtins = 0;
	if (ft_strcmp(tmp->cmd, "echo"))
		tmp->builtins = 1;
	else if (ft_strcmp(tmp->cmd, "cd"))
		tmp->builtins = 1;
	else if (ft_strcmp(tmp->cmd, "export"))
		tmp->builtins = 1;
	else if (ft_strcmp(tmp->cmd, "unset"))
		tmp->builtins = 1;
	else if (ft_strcmp(tmp->cmd, "pwd"))
		tmp->builtins = 1;
	else if (ft_strcmp(tmp->cmd, "env"))
		tmp->builtins = 1;
	else if (ft_strcmp(tmp->cmd, "exit"))
		tmp->builtins = 1;
	return (tmp->builtins);
}
