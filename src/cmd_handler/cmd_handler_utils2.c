/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:58:00 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/14 11:04:31 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds_num(char *input)
{
	return (count_rows_del(input, '|'));
}

int	clean_input(char *input)
{
	char	*tmp;

	tmp = ft_strtrim(input, " ");
	if (ft_strlen(tmp) == 0)
		return (free(tmp), 0);
	free(tmp);
	return (1);
}

void	ft_expand(t_cmd *c)
{
	char		*tmp;
	char		*t2;
	char		**tmptmp;
	int			first;
	int			in;

	in = 0;
	if (!clean_input(c->input))
		return ;
	first = first_quote(c->input);
	tmp = expand_tokens(c->input, first, in);
	tmptmp = ft_split(tmp, ' ');
	t2 = ft_echo_quots(tmptmp, &c->enviro);
	if (t2)
	{
		c->expanded_input = (char *)malloc(sizeof(char) * (ft_strlen(t2) + 1));
		ft_strcpy(c->expanded_input, t2);
	}
	else
	{
		c->expanded_input = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1));
		ft_strcpy(c->expanded_input, tmp);
	}
	(free(tmp), free_matrix(tmptmp));
}

char	*desk_to_space(char *input)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(input) + 1));
	res[ft_strlen(input)] = '\0';
	while (input[i])
	{
		if (input[i] == '\\')
			res[i] = ' ';
		else
			res[i] = input[i];
		i++;
	}
	return (res);
}
