/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:46:37 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/12 15:35:13 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_rows(void **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		i++;
	}
	return (i);
}

void	*verify_redirect_stdin(char *cmd)
{
	int		i;
	char	**redirect;
	char	*trimed_str;
	char	**rd;
	t_redirect	*redirec;

	i = 1;
	redirec = NULL;
	if (ft_strchr(cmd, '<'))
	{
		redirec = (t_redirect *)malloc(sizeof(t_redirect));
		redirect = ft_split(cmd, '<');
		redirec->count = (count_rows((void **)redirect) - 1);
		redirec->fd_list = (int *)malloc(sizeof(int) * redirec->count);
		while (redirect[i])
		{
			rd = ft_split(redirect[i], ' ');
			trimed_str = ft_strtrim(rd[0], " ");
			redirec->fd_list[i - 1] = open(trimed_str, O_RDONLY);
			free(trimed_str);
			i++;
		}
		return (redirec);
	}
	else
		return (NULL);
}

int	verify_fd(t_redirect *redirec)
{
	int	i;

	i = 0;
	while (i < redirec->count)
	{
		if (redirec->fd_list[i] < 0)
			return (0);
		i++;
	}
	return(1);
}

void	redirect_stdin_test(t_prec *prec, char *env[])
{
	int	pipe_fd[2];
	char	**full_cmd;
	char	*path;
	t_child_p	*child;

	pipe_fd[0] = prec->redirect->fd_list[prec->redirect->count - 1];
	pipe_fd[1] = -1;
	child = new_child_p(pipe_fd);
	full_cmd = ft_split(prec->cmd, ' ');
	if (child->pid == 0)
	{
		path = cmd_exist(full_cmd[0]);
		if (path)
		{
			dup2(pipe_fd[0], STDIN_FILENO);
			if (execve(path, prec->args, env) == -1)
			{
				perror("Erro ao executar execve");
				return ;
			}
			close(pipe_fd[0]);
		}
	}
}

void	redirect_stdin(t_cmd *cmd, char *env[])
{
	int	pipe_fd[2];
	char	**full_cmd;
	char	*path;
	t_child_p	*child;

	pipe_fd[0] = cmd->redirect->fd_list[cmd->redirect->count - 1];
	pipe_fd[1] = -1;
	child = new_child_p(pipe_fd);
	full_cmd = ft_split(cmd->input, ' ');
//	if (child->pid == 0)
//	{
		path = cmd_exist(full_cmd[0]);
		if (path)
		{
			int	i = 0;
			//while (cmd->args[i])
			//	printf("\n%s", cmd->args[i++]);
//			dup2(pipe_fd[0], STDIN_FILENO);
//			if (execve(path, cmd->args, env) == -1)
		//	{
		//		perror("Erro ao executar execve");
		//		return ;
		//	}
		//	close(pipe_fd[0]);
		}
//	}
}
