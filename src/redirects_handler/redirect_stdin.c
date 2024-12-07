/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:46:37 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/07 02:39:47 by lleodev          ###   ########.fr       */
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
	int			i;
	char		**redirect;
	char		*trimed_str;
	char		**rd;
	t_redirect	*redirec;

	i = 0;
	if (ft_findchar(cmd, '<'))
	{
		redirec = initialize_redirect();
		redirect = ft_split(cmd, '<');
		redirec->count = (count_rows((char **)redirect) - 1);
		redirec->fd_list = (int *)malloc(sizeof(int) * redirec->count);
		while (redirect[++i])
		{
			if (verify_quotes(redirect[i]))
			{
				trimed_str = get_content_quotes(redirect[i]);
				printf("HERE: %s\n", trimed_str);
			}
			else
			{
				rd = ft_split(redirect[i], ' ');
				trimed_str = ft_strtrim(rd[0], " ");
				free_matrix(rd);
			}
			redirec->fd_list[i - 1] = open(trimed_str, O_RDONLY);
			free(trimed_str);
		}
		return (free_matrix(redirect), redirec);
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
	return (1);
}

int	verify_dup_redirect_stdin(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '>')
			count++;
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

void	handle_stdin(t_prec *p)
{
	char	*tmp;
	char	**tmp2;
	char	*name;

	p->stdin_redirect = verify_redirect_stdin(p->input);
	if (p->stdin_redirect)
	{
		if (verify_heredoc(p->input) > 0)
		{
			tmp2 = ft_split(p->input, ' ');
			tmp = ft_strtrim(tmp2[2], " ");
			p->stdin_redirect->fd_list[p->stdin_redirect->count - 1]
				= handle_heredoc(tmp, name);
			p->stdin = p->stdin_redirect->fd_list[p->stdin_redirect->count - 1];
			free(tmp);
			free_matrix(tmp2);
		}
		else if (verify_heredoc(p->input) < 0)
			return (printf("error: Invalid token\n"), NULL);
		else if (verify_heredoc(p->input) == 0)
			p->stdin
				= p->stdin_redirect->fd_list[p->stdin_redirect->count - 1];
	}
	else
		p->stdin = STDIN_FILENO;
}
