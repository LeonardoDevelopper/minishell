/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_handler_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:48:48 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/09 16:32:40 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	verify_dup_redirect_stdin(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '>')
			count++;
		else
		{
			if ((count == 2) && input[i + 1] != '>')
				return (1);
			else if (count == 1 && input[i + 1] != '>')
				return (0);
		}
		i++;
	}
	return (-1);
}

int	verify_fd(t_redirect *redirec)
{
	int	i;

	i = 0;
	while (i < redirec->count)
	{
		if (redirec->fd_list[i] < 0)
			return (0);
		i++;
	}
	return (1);
}

char	*handle_literal(char *input)
{
	char	*tmp;
	char	*tmp2;
	int		first;

	first = first_quote(input);
	tmp = get_content_quotes(input, first);
	if (ft_findchar(tmp, '>'))
	{
		tmp = remove_char(tmp, '>');
		tmp2 = ft_strtrim(tmp, " ");
		free(tmp);
		tmp = (char *)malloc(sizeof(char) * (ft_strlen(tmp2) + 1));
		ft_strlcpy(tmp, tmp2, (ft_strlen(tmp2) + 1));
		free(tmp2);
		return (tmp);
	}
	return (tmp);
}

char	*handle_no_literal(char *input)
{
	char	**rd;
	char	*tmp;

	rd = ft_split(input, ' ');
	tmp = ft_strtrim(rd[0], " ");
	free_matrix(rd);
	return (tmp);
}

int	verify_dup_redirect_stdout(char *input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '>')
		{
			count++;
		}
		else
		{
			if ((count == 2) && input[i + 1] != '>')
				return (1);
			else if (count == 1 && input[i + 1] != '>')
				return (0);
		}
		i++;
	}
	return (-1);
}
