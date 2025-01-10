/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:52:00 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/09 14:58:44 by lleodev          ###   ########.fr       */
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

int	verify_quotes(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

char	*get_content_quotes(char *input, int first)
{
	int		i;
	int		j;
	char	*content;

	i = 0;
	j = 0;
	i += skip_space(input, i);
	content = (char *)malloc(sizeof (char) * 1024);
	if (first && (input[i] == first))
		i++;
	while (input[i])
	{
		if ((input[i] == first))
			break ;
		content[j++] = input[i];
		i++;
	}
	content[j] = '\0';
	return (content);
}
