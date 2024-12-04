/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:00 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/04 14:28:13 by lleodev          ###   ########.fr       */
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

char	*quote(char *cmd)
{
	char	*quote;

	quote = cmd;
	if (d_quote(cmd) == 1)
	{
		quote = ft_strjoin_ptr(quote, readline("\n >_ "));
		while (d_quote(quote) < 2)
		{
			printf("%s", quote);
			quote = ft_strjoin_ptr(quote, readline("\n >_ "));
		}
	}
	return (quote);
}

int	ft_handle_tokens(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\\' || input[i] == ';' || input[i] == '&')
		{
			ft_putstr_fd("error: Unexpected token at the input\n",
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
