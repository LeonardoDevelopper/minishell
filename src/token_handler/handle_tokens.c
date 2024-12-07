/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:34:52 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/07 11:56:45 by lleodev          ###   ########.fr       */
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
	if (i > 0)
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
	char	*new;

	i = 0;
	new = epur_str(input);
	len = ft_strlen(new);
	while (new[i])
	{
		if (new[i] == '"' || new[i] == '\'')
		{
			i += skip_content_in_quote(new, i);
			if (i >= len)
            	break ;
		}
		if ((i + 1) < len)
		{
			if ((new[i] == '<' && (new[i + 1] == '>' || new[i + 1] == '|'))
				|| (new[i] == '>' && (new[i + 1] == '<' || new[i + 1] == '|')))
				return (free(new), 1);
			if (new[i] == '|' && (new[i + 1] == '|'
					|| new[i + 1] == '>' || new[i + 1] == '<'))
				return (free(new), 1);
		}
		if ((i + 2) < len)
		{
			if ((new[i] == '<' || new[i] == '>' || new[i] == '|')
				&& (new[i + 2] == '<' || new[i + 2] == '>'
					|| new[i + 2] == '|'))
				return (free(new), 1);
		}
		i++;
	}
	return (free(new), 0);
}

int	handle_special_chr(char *input)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(input);
	while (i <= len)
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
