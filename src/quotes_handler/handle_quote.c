/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:00 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/22 14:52:02 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	d_quote(char *cmd)
{
	int	counter;
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
	//char	*tmp;

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
