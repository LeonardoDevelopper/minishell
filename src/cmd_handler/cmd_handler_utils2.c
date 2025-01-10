/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:58:00 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/10 21:28:41 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds_num(char *input)
{
	return (count_rows_del(input, '|'));
}

char	*ft_expand(t_cmd *cmd, t_prec *prec)
{
	char	**tmp2;

	tmp2 = handle_non_builtin1(prec->input);
	free(prec->input);
	prec->input = ft_echo(tmp2, &cmd->enviro);
	free_matrix(tmp2);
	if (!ft_strlen(prec->input))
		return (NULL);
	return (prec->input);
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
