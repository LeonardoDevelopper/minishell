/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:08:03 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/11 08:48:02 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->precedence)
			free_prec(cmd->precedence);
	}
}

void	free_redirects(t_prec *prec)
{
	if (prec->stdin_redirect)
	{
		free(prec->stdin_redirect->fd_list);
		free(prec->stdin_redirect);
	}
	if (prec->stdout_redirect)
	{
		free(prec->stdout_redirect->fd_list);
		free(prec->stdout_redirect);
	}
}

void	free_prec(t_prec **prec)
{
	int	i;

	i = 0;
	while (prec[i])
	{
		free_redirects(prec[i]);
		if (prec[i]->cmd)
			free(prec[i]->cmd);
		if (prec[i]->path)
			free(prec[i]->path);
		if (prec[i]->input)
			free(prec[i]->input);
		if (prec[i]->args)
			free_matrix(prec[i]->args);
		if (prec[i]->child)
			free(prec[i]->child);
		free(prec[i]);
		i++;
	}
	free(prec);
}

static int	all_digit(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	handle_exit(t_cmd *cmd)
{
	char	**tmp;
	char	*trimmed_str;
	int		count;

	tmp = ft_split(cmd->input, ' ');
	count = count_rows_splited(tmp);
	trimmed_str = ft_strtrim(tmp[0], " ");
	if (ft_strcmp(trimmed_str, "exit") == 1)
	{
		add_history(cmd->input);
		if (count == 2 || count == 1)
		{
			printf("Bye Bye\n");
			if (!all_digit(tmp))
				ft_putstr_fd("exit: non numeric argument provided\n", 2);
			free_left(trimmed_str, cmd);
			ft_exit(tmp, count, NULL, 1);
		}
		else
		{
			return (free_left2(trimmed_str, cmd), free_matrix(tmp),
				ft_putstr_fd("exit: too many arguments\n", 2), 0);
		}
	}
	return (free(trimmed_str), free_matrix(tmp), 1);
}
