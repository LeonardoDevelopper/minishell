/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:41:57 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/09 16:24:09 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	in_quotes(int in)
{
	if (in)
		in = 0;
	else
		in = 1;
	return (in);
}

void	replace_in_quotes(char *dest, char *src, int index1, int index2)
{
	if (src[index2] == 32 || src[index2] <= 13)
		dest[index1] = '\\';
	else
		dest[index1] = src[index2];
}

int	cpy_args(char *dst, char *src, int j)
{
	int	i;

	i = 0;
	while (src[i])
		dst[j++] = src[i++];
	dst[j++] = ' ';
	return (j);
}

int	count_char(char *str, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	first_quote(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\'')
			return ('\'');
		else if (tmp[i] == '"')
			return ('"');
		i++;
	}
	return (0);
}
