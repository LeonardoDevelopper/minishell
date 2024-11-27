/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:37:56 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/27 11:38:25 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		verify_heredoc(char *input)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (input[i])
    {
        if (input[i] == '<')
        {
            count++;
        }
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

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*start;
	size_t	total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *) malloc((total_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	start = result;
	while (*s1 != '\0')
	{
		*result = *s1;
		result++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*result = *s2;
		result++;
		s2++;
	}
	*result = '\0';
	return (start);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == '\0' || *s2 == '\0')
	{
		if ((*s1 - *s2) != 0)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*handle_heredoc(char *del)
{
    char    *line;
    char    *result;

    while (1)
    {
        line = readline(">_ ");
    }
    return (NULL);
}

