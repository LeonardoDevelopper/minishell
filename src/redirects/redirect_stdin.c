/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:46:37 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/23 08:46:39 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	verify_redirect_stdin(char *cmd)
{
	int		i;
	int		fd;
	char	**redirect;
	char	*trimed_str;

	i = 0;
	fd = -2;
	redirect = NULL;
	while (cmd[i])
	{
		if (cmd[i] == '<')
		{
			redirect = ft_split(cmd, '<');
			trimed_str = ft_strtrim(redirect[1], " ");
			fd = open(trimed_str, O_RDONLY);
			free_matrix(redirect);
			return (fd);
		}
		i++;
	}
	return (fd);
}


char	*read_file(int fd)
{
	char	*file_content;

	file_content = read_stdout_child(fd);
	return (file_content);
}

char	*redirect_stdin(char *cmd)
{
	int	fd;

	fd = verify_redirect_stdin(cmd);
	if (fd == -1)
	{
		return (NULL);
	}
	else if (fd >= 0)
		return (read_file(fd));
	return (NULL);
}
