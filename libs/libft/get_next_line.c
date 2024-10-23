/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:50:16 by lleodev           #+#    #+#             */
/*   Updated: 2024/06/20 13:50:18 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_line(int fd, char *buf, char *backup)
{
	int		read_l;
	char	*char_temp;

	read_l = 1;
	while (read_l != '\0')
	{
		read_l = read(fd, buf, BUFFER_SIZE);
		if (read_l == -1)
			return (0);
		else if (read_l == 0)
			break ;
		buf[read_l] = '\0';
		if (!backup)
			backup = ft_strdup_custom("");
		char_temp = backup;
		backup = ft_strjoin_custom(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr_custom(buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr_custom(line, count + 1, ft_strlen_custom(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
