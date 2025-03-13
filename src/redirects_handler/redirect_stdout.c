/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdout.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:31:13 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/14 08:41:56 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*verify_redirect_stdout(char *input)
{
	t_redirect	*redir;
	char		**redirect;
	char		*tmp;
	int			first;

	if (ft_findchar(input, '>'))
	{
		redir = initialize_redirect();
		redirect = ft_split(input, '>');
		if (verify_quotes(redirect[1]))
		{
			first = first_quote(redirect[1]);
			tmp = get_content_quotes(redirect[1], first);
		}
		else
			tmp = ft_strtrim(redirect[1], " ");
		redir->count = count_rows((char **)redirect);
		if (redir->count > 1)
		{
			redir->fd_list = (int *)malloc(sizeof(int) * 1);
			return (free_matrix(redirect), try_open(redir, input, tmp));
		}
		return (free_matrix(redirect), free(redir), NULL);
	}
	return (NULL);
}

void	*try_open(t_redirect *redir, char *input, char *tmp)
{
	if (verify_dup_redirect_stdout(input) < 0)
		return (free(redir), NULL);
	else if (!verify_dup_redirect_stdout(input))
		redir->fd_list[0] = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (verify_dup_redirect_stdout(input))
		redir->fd_list[0] = open(tmp, O_WRONLY | O_CREAT | O_APPEND, 0644);
	free(tmp);
	return (redir);
}

void	handle_stdout(t_prec *prec)
{
	if (prec->stdin_redirect)
	{
		if (!verify_fd(prec->stdin_redirect))
			return (prec->stdout = STDOUT_FILENO, ft_putchar_fd('\0', 1));
	}
	prec->stdout_redirect = verify_redirect_stdout(prec->input);
	prec->num_args = count_rows_splited(prec->args);
	if (prec->stdout_redirect)
		prec->stdout = prec->stdout_redirect->fd_list[0];
	else
		prec->stdout = STDOUT_FILENO;
}
