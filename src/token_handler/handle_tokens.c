/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:34:52 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/07 00:58:27 by lleodev          ###   ########.fr       */
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

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '"' || cmd[i] == '\'')
			i += skip_content_in_quote(cmd, i);
		if ((cmd[0] == '|' || cmd[0] == '<' || cmd[0] == '>'))
			return (1);
		if (cmd[i] == '|' && cmd[i + 1] == '|')
			return (1);
		i++;
	}
	if (cmd[i - 1] == '|' || cmd[i - 1] == '<' || cmd[i - 1] == '>')
		return (1);
	return (0);
}

int	handle_redirect_token(char *input)
{
	int		i;
	char	*new;

	i = 0;
	new = epur_str(input);
	while (new[i])
	{
		if (new[i] == '"' || input[i] == '\'')
			i += skip_content_in_quote(new, i);
		if ((i + 2) < ft_strlen(new))
		{
			if ((new[i] == '<' && (new[i + 1] == '>' || new[i + 1] == '|'))
				|| (new[i] == '>' && (new[i + 1] == '<' || new[i + 1] == '|')))
				return (1);
			if (new[i] == '|' && (new[i + 1] == '|'
					|| new[i + 1] == '>' || new[i + 1] == '<'))
				return (1);
			if ((new[i] == '<' || new[i] == '>' || new[i] == '|')
				&& (new[i + 2] == '<' || new[i + 2] == '>'
					|| new[i + 2] == '|'))
				return (1);
		}
		i++;
	}
	return (0);
}

int	handle_special_chr(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			i += skip_content_in_quote(input, i);
		if (input[i] == '\\' || input[i] == ';' || input[i] == '&')
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
