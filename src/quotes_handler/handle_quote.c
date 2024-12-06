/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:00 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/06 20:18:50 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	d_quote(char *cmd)
{
	int		counter;
	char	*ptr_cmd;

	ptr_cmd = cmd;
	counter = 0;
	while (*ptr_cmd)
	{
		if (*ptr_cmd == '"')
			counter++;
		ptr_cmd++;
	}
	return (counter);
}

int	check_cmd_start_end(char *cmd)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strtrim(cmd, " ");
	while (new[i])
	{
		if (new[0] == '|' || new[0] == '<' || new[0] == '>')
			return (1);
		i++;
	}
	if (new[i - 1] == '|' || new[i - 1] == '<' || new[i - 1] == '>')
		return (1);
	return (0);
}

int	ft_handle_tokens(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\\' || input[i] == ';' || input[i] == '&'
			|| (input[i] == '|' && input[i + 1] == '|')
			|| check_cmd_start_end(input))
		{
			ft_putstr_fd("error: syntax error near unexpected token\n",
				STDERR_FILENO);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_handle_quotes(char *input)
{
	if (count_char(input, '"') % 2 != 0)
	{
		ft_putstr_fd("error: Unclosed quote\n", STDERR_FILENO);
		return (0);
	}
	return (1);
}

char	**handle_double_quotes(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		i++;
	}
}
