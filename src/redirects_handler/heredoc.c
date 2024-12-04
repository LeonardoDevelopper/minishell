/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:37:56 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/04 12:40:33 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	verify_heredoc(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '<')
			count++;
		else
		{
			if ((count == 2) && input[i + 1] != '<')
				return (1);
			else if (count == 1 && input[i + 1] != '<')
				return (0);
		}
		i++;
	}
	return (-1);
}

void	create_dir(char *dir)
{
	t_child_p	*child;
	char		*args[4];

	child = new_child_p(NULL);
	args[0] = "/bin/mkdir";
	args[1] = dir;
	args[2] = "-p";
	args[3] = NULL;
	if (child->pid == 0)
	{
		execve(args[0], args, NULL);
		perror("Error: can't create directory");
		exit(1);
	}
	waitpid(child->pid, NULL, 0);
	free(child);
}

void	remove_old_file(char *dir)
{
	t_child_p	*child;
	char		*tmp;
	char		*args[4];

	tmp = ft_strjoin(dir, "/heredoc");
	args[0] = "/bin/rm";
	args[1] = tmp;
	args[2] = "-r";
	args[3] = NULL;
	child = new_child_p(NULL);
	if (child->pid == 0)
	{
		execve(args[0], args, NULL);
		perror("Error: cleaning old file");
		exit(1);
	}
	waitpid(child->pid, NULL, 0);
	free(tmp);
	free(child);
}

void	heredoc(char *line, char *del, int fd)
{
	while (1)
	{
		line = readline(">_ ");
		if (line && *line)
		{
			if (ft_strcmp(line, del))
			{
				free(del);
				free(line);
				exit(0);
			}
			ft_putstr_fd(line, fd);
			ft_putchar_fd('\n', fd);
			free(line);
		}
	}
}

int	handle_heredoc(char *del, char *name)
{
	int			fd;
	char		*line;
	char		*home;
	char		*dir;
	t_child_p	*child;

	home = getenv("HOME");
	dir = ft_strjoin(home, "/tmp");
	create_dir(dir);
	remove_old_file(dir);
	name = ft_strjoin(dir, "/heredoc");
	fd = open(name, O_RDWR | O_CREAT | O_APPEND, 0644);
	child = new_child_p(NULL);
	free(dir);
	if (child->pid == 0)
	{
		if (fd <= 0)
			return (free(name), -1);
		heredoc(line, del, fd);
	}
	waitpid(child->pid, NULL, 0);
	close(fd);
	free(child);
	fd = open(name, O_RDONLY);
	return (free(name), fd);
}
