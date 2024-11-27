/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:31:13 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/21 14:43:17 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    *verify_redirect_stdout(char *input)
{
    t_redirect  *redirect_stdout;
    char    **redirect;
    char    *str_trimmed;

    redirect_stdout = (t_redirect *)malloc(sizeof(t_redirect));
    redirect = ft_split(input, '>');
    str_trimmed = ft_strtrim(redirect[1], " ");
    redirect_stdout->count = count_rows((void **)redirect);
    if (redirect_stdout->count > 1)
    {
        redirect_stdout->fd_list = (int *)malloc(sizeof(int) * 1);
        if (verify_dup_redirect_stdout(input) < 0)
            return (NULL);
        else if (!verify_dup_redirect_stdout(input))
            redirect_stdout->fd_list[0] = open(str_trimmed, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        else if (verify_dup_redirect_stdout(input))
            redirect_stdout->fd_list[0] = open(str_trimmed, O_WRONLY | O_CREAT | O_APPEND, 0644);
        free_matrix(redirect);
        if (redirect_stdout->fd_list[0] < 0)
            return (NULL);
        else
            return (redirect_stdout);
    }
    return (NULL);
}

int verify_dup_redirect_stdout(char *input)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (input[i])
    {
        if (input[i] == '>')
        {
            count++;
        }
        else
        {
            if ((count == 2) && input[i + 1] != '>')
                return (1);
            else if (count == 1 && input[i + 1] != '>')
                return (0);
        }
        i++;
    }
    return (-1);
}
