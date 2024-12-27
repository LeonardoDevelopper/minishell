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

int	close_heredoc(int signal)
{
	char	*home;
	char	*dir;

	home = getenv("HOME");
	dir = ft_strjoin(home, "/tmp");
	remove_old_file(dir);
	exit(0);
}

void	heredoc(char *line, char *del, int fd)
{
	signal(SIGINT, close_heredoc);
	while (1)
	{
		line = readline("heredoc>_ ");
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

int	handle_heredoc(char *del, char *n)
{
	int			fd;
	char		*line;
	char		*home;
	char		*dir;
	t_child_p	*ch;

	home = getenv("HOME");
	dir = ft_strjoin(home, "/tmp");
	create_dir(dir);
	remove_old_file(dir);
	n = ft_strjoin(dir, "/.heredoc");
	line = ft_itoa(getpid());
	n = ft_strjoin_ptr(n, line);
	free(line);
	fd = open(n, O_RDWR | O_CREAT | O_APPEND, 0644);
	ch = new_child_p(NULL);
	free(dir);
	if (ch->pid == 0)
		heredoc(line, del, fd);
	waitpid(ch->pid, NULL, 0);
	if(open(n, O_RDONLY) < 0)
		return (close(fd), free(n), free(ch), cancel_heredoc(dir));
	return (close(fd), fd = open(n, O_RDONLY), free(n), free(ch), fd);

}
