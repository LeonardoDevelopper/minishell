/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:34:52 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/09 11:32:54 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_space(char *cmd, int i)
{
	while (cmd[i] && cmd[i] == 32 || (cmd[i] > 9 && cmd[i] <= 13))
		i++;
	return (i);
}

int	check_cmd_tokens(char *cmd)
{
	int	i;
	int	len;

	len = ft_strlen(cmd);
	i = 0;
	while (i < len)
	{
		if (cmd[i] == '"' || cmd[i] == '\'')
			i += skip_content_in_quote(cmd, i);
		if ((cmd[0] == '|' || cmd[0] == '<' || cmd[0] == '>'))
			return (1);
		if ((i + 1) < len)
		{
			if (cmd[i] == '|' && cmd[i + 1] == '|')
				return (1);
		}
		i++;
	}
	if (i < len)
	{
		if (cmd[i - 1] == '|' || cmd[i - 1] == '<' || cmd[i - 1] == '>')
			return (1);
	}
	return (0);
}

int	handle_redirect_token(char *input)
{
	int		i;
	int		len;
	char	*n;

	i = 0;
	n = epur_str(input);
	len = ft_strlen(n);
	while (n[i])
	{
		if (n[i] == '"' || n[i] == '\'')
		{
			i += skip_content_in_quote(n, i);
			if (i >= len)
				break ;
		}
		if ((i + 1) < len)
		{
			if ((n[i] == '<' && (n[i + 1] == '>' || n[i + 1] == '|'))
				|| (n[i] == '>' && (n[i + 1] == '<' || n[i + 1] == '|')))
				return (free(n), 1);
			if (n[i] == '|' && (n[i + 1] == '|'
					|| n[i + 1] == '>' || n[i + 1] == '<'))
				return (free(n), 1);
		}
		if ((i + 2) < len)
		{
			if ((n[i] == '<' || n[i] == '>' || n[i] == '|')
				&& (n[i + 2] == '<' || n[i + 2] == '>' || n[i + 2] == '|'))
				return (free(n), 1);
		}
		i++;
	}
	return (free(n), 0);
}

int	handle_special_chr(char *input)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(input);
	while (i < len)
	{
		if (input[i] == '"' || input[i] == '\'')
			i += skip_content_in_quote(input, i);
		if (i >= len)
			break ;
		if (i < len && input[i] == '\\' || input[i] == ';' || input[i] == '&')
			return (1);
		i++;
	}
	return (0);
}

int	ft_handle_tokens(char *input)
{
	if (handle_special_chr(input) || check_cmd_tokens(input)
		|| handle_redirect_token(input))
	{
		ft_putstr_fd("error: syntax error near unexpected token\n",
			STDERR_FILENO);
		return (0);
	}
	return (1);
}
