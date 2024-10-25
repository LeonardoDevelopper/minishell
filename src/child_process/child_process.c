/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:38:41 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/14 08:38:43 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_child_p	*new_child_p(void *pipe)
{
	t_child_p	*child;

	child = (t_child_p *)malloc(sizeof(t_child_p));
	child->pid = fork();

	if (pipe)
		child->pipe_fd = (int *)pipe;
	else
		child->pipe_fd = NULL;
	if (child->pid == -1)
	{
		perror("fork");
		return (NULL);
	}
	return (child);
}

void	run_child_p(char *cmd, char **abs_path, t_child_p *child, char *env[])
{
	int	*fd;

	if (child->pipe_fd)
	{
		fd = (int *)child->pipe_fd;
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
	}
	execve(cmd, abs_path, env);
	if (child->pipe_fd)
		close(fd[1]);
	perror("\nexecve: ");
	exit(0);
}

char	*read_stdout_child(int fd)
{
	char	*output;
	char	*buffer;
	int		n_bytes;

	n_bytes = 1;
	output = NULL;
	output = malloc(sizeof(char ) * 43);
	n_bytes = read(fd, output, 42);
	output[n_bytes] = '\0';
	while (n_bytes > 0)
	{
		buffer = malloc(sizeof(char ) * 43);
		n_bytes =  read(fd, buffer, 42);
		if (n_bytes > 0)
			buffer[n_bytes] = '\0';
		output = ft_strjoin_ptr(output, buffer);
		free(buffer);
	}
	return (output);
}

void	print_stdout_child(char *buffer)
{
	if (buffer)
		printf("%s", buffer);
}
