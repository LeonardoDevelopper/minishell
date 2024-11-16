/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:31:13 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/16 14:30:51 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    *verify_redirect_stdout(char *input)
{
    t_redirect  *redirect_stdout;
    char    **redirect;

    redirect_stdout = (t_redirect *)malloc(sizeof(t_redirect));
    redirect = ft_split(input, '>');
    redirect_stdout->count = count_rows((void **)redirect);
    if (redirect_stdout->count > 1)
    {
        redirect_stdout->fd_list = (int *)malloc(sizeof(int) * 1);
        redirect_stdout->fd_list[0] = open(redirect[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        free_matrix(redirect);
        if (redirect_stdout->fd_list[0] < 0)
            return (NULL);
        else
            return (redirect_stdout);
    }
    return (NULL);
}

void	redirect_stdout_test(t_prec *prec, char *env[])
{
    
}