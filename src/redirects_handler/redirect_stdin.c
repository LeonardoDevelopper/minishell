/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:46:37 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/09 13:26:18 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*verify_redirect_stdin(char *cmd)
{
	int			i;
	char		**redirect;
	char		*trimed_str;
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
				trimed_str = handle_literal(redirect[i]);
			else
				trimed_str = handle_no_literal(redirect[i]);
			redirec->fd_list[i - 1] = open(trimed_str, O_RDONLY);
			free(trimed_str);
		}
		return (free_matrix(redirect), redirec);
	}
	else
		return (NULL);
}

void	*handle_stdin(t_prec *p)
{
	t_tmp	t;
	char	*name;

	name = NULL;
	p->stdin_redirect = verify_redirect_stdin(p->input);
	if (p->stdin_redirect)
	{
		if (verify_heredoc(p->input) > 0)
		{
			t.tmp2 = ft_split(p->input, ' ');
			t.tmp = ft_strtrim(t.tmp2[2], " ");
			p->stdin_redirect->fd_list[p->stdin_redirect->count - 1]
				= handle_heredoc(t.tmp, name);
			p->stdin = p->stdin_redirect->fd_list[p->stdin_redirect->count - 1];
			free_two(t.tmp, t.tmp2);
		}
		else if (verify_heredoc(p->input) < 0)
			return (printf("error: Invalid token\n"), NULL);
		else if (verify_heredoc(p->input) == 0)
			p->stdin
				= p->stdin_redirect->fd_list[p->stdin_redirect->count - 1];
	}
	else
		p->stdin = STDIN_FILENO;
	return (NULL);
}
