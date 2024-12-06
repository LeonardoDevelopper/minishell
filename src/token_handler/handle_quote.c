/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:00 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/06 23:35:26 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_content_in_quote(char *input, int i)
{
	if (input[i] == '"')
	{
		while (input[i] && input[i] != '"')
			i++;
	}
	if (input[i] == '\'')
	{
		while (input[i] && input[i] != '\'')
			i++;
	}
	return (i);
}

int	ft_handle_quotes(char *input)
{
	if (count_char(input, '"') % 2 != 0 || count_char(input, '\'') % 2 != 0)
	{
		ft_putstr_fd("error: Unclosed quote\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}
