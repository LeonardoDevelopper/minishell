/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:46:37 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/03 09:20:32 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_rows(void **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		i++;
	}
	return (i);
}

void	*verify_redirect_stdin(char *cmd)
{
	int		i;
	char	**redirect;
	char	*trimed_str;
	char	**rd;
	t_redirect	*redirec;

	i = 1;
	redirec = NULL;
	if (ft_strchr(cmd, '<'))
	{
		redirec = (t_redirect *)malloc(sizeof(t_redirect));
		redirect = ft_split(cmd, '<');
		redirec->count = (count_rows((void **)redirect) - 1);
		redirec->fd_list = (int *)malloc(sizeof(int) * redirec->count);
		while (redirect[i])
		{
			rd = ft_split(redirect[i], ' ');
			trimed_str = ft_strtrim(rd[0], " ");
			redirec->fd_list[i - 1] = open(trimed_str, O_RDONLY);
			free(trimed_str);
			free_matrix(rd);
			i++;
		}
		free_matrix(redirect);
		return (redirec);
	}
	else
		return (NULL);
}

int	verify_fd(t_redirect *redirec)
{
	int	i;


	i = 0;
	while (i < redirec->count)
	{
		if (redirec->fd_list[i] < 0)
			return (0);
		i++;
	}
	return(1);
}

int verify_dup_redirect_stdin(char *input)
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

void	handle_stdin(t_prec * prec)
{
	prec->stdin_redirect = verify_redirect_stdin(prec->input);
	if (prec->stdin_redirect)
	{
		if (verify_heredoc(prec->input) > 0)
		{
			prec->stdin_redirect->fd_list[prec->stdin_redirect->count - 1] = handle_heredoc(ft_strtrim(ft_split(prec->input, ' ')[2], " "));
			prec->stdin = prec->stdin_redirect->fd_list[prec->stdin_redirect->count - 1];
		}
		else if (verify_heredoc(prec->input) < 0)
			return (printf("error: Invalid token\n"), NULL);
		else if (verify_heredoc(prec->input) == 0)
			prec->stdin = prec->stdin_redirect->fd_list[prec->stdin_redirect->count - 1];
	}
	else
		prec->stdin = STDIN_FILENO;
}