/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:31:13 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/04 09:35:06 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*verify_redirect_stdout(char *input)
{
	t_redirect	*redir;
	char		**redirect;
	char		*tmp;

	redir = initialize_redirect();
	redirect = ft_split(input, '>');
	tmp = ft_strtrim(redirect[1], " ");
	redir->count = count_rows((void **)redirect);
	free_matrix(redirect);
	if (redir->count > 1)
	{
		redir->fd_list = (int *)malloc(sizeof(int) * 1);
		if (verify_dup_redirect_stdout(input) < 0)
			return (free(redir), NULL);
		else if (!verify_dup_redirect_stdout(input))
			redir->fd_list[0] = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (verify_dup_redirect_stdout(input))
			redir->fd_list[0] = open(tmp, O_WRONLY | O_CREAT | O_APPEND, 0644);
		free(tmp);
		if (redir->fd_list[0] < 0)
			return (free(redir), NULL);
		else
			return (redir);
	}
	return (free(redir), NULL);
}

int	verify_dup_redirect_stdout(char *input)
{
	int	i;
	int	count;

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

void	handle_stdout(t_prec *prec)
{
	prec->stdout_redirect = verify_redirect_stdout(prec->input);
	prec->num_args = count_rows_splited(prec->args);
	if (prec->stdout_redirect)
		prec->stdout = prec->stdout_redirect->fd_list[0];
	else
		prec->stdout = STDOUT_FILENO;
}
