/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:37:56 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/28 15:25:50 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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




char	*handle_heredoc(char *del)
{
    char    *line;
    char    *result;

    while (1)
    {
        line = readline(">_ ");
		if (line && *line)
		{
			printf("\nline: %s\n", line);
			if (ft_strcmp(line, del))
				return (NULL);
		}
    }
    return (NULL);
}

