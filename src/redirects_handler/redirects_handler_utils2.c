/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_handler_utils2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:09:27 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/06 08:09:29 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cancel_heredoc(char *dir)
{
	int		fd;
	char	*tmp;
	char	*home;

	home = getenv("HOME");
	dir = ft_strjoin(home, "/tmp");
	tmp = ft_strjoin(dir, "/heredoc_empty");
	fd = open(tmp, O_RDWR | O_CREAT);
	free(dir);
	free(tmp);
	return (fd);
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
	char		*tmp2;

	tmp2 = ft_itoa(getppid());
	tmp = ft_strjoin(dir, "/.heredoc");
	tmp = ft_strjoin_ptr(tmp, tmp2);
	free(tmp2);
	args[0] = "/bin/rm";
	args[1] = tmp;
	args[2] = "-rf";
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
