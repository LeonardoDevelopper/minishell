/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:37:56 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/30 00:37:09 by lleodev          ###   ########.fr       */
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

int handle_heredoc(char *del)
{
    int     fd;
    char    *line;
    char    *home;
    t_child_p   *child;

    child = new_child_p(NULL);
    home = getenv("HOME");
    char    *dir = ft_strjoin(home, "/tmp");
    if (child->pid == 0)
    {
        char *args[] = {"/bin/mkdir", dir, "-p", NULL};
        execve(args[0], args, NULL);
        perror("Erro ao criar diretório");
        exit(1);
    }
    waitpid(child->pid, NULL, 0);
    free(child);
    child = new_child_p(NULL);
    if (child->pid == 0)
    {
        char *args[] = {"/bin/rm", ft_strjoin(dir, "/heredoc"), "-r", NULL};
        execve(args[0], args, NULL);
        perror("Erro ao criar diretório");
        exit(1);
    }
    waitpid(child->pid, NULL, 0);
    free(child);
    fd = open(ft_strjoin(dir, "/heredoc"), O_RDWR | O_CREAT | O_APPEND, 0644);
    child = new_child_p(NULL);
    if (child->pid == 0)
    {
        if (fd <= 0)
            return (printf("cannot open: %d", fd), -1);
        while (1)
        {
            line = readline(">_ ");
            if (line && *line)
            {
                if (ft_strcmp(line, del))
                    exit(0);
                ft_putstr_fd(ft_strjoin(line, "\n"), fd);
            }
        }
    }
    waitpid(child->pid, NULL, 0);
    close(fd);
    return (open(ft_strjoin(dir, "/heredoc"), O_RDONLY));
}
