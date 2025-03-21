/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:43:38 by aborges           #+#    #+#             */
/*   Updated: 2025/01/09 12:02:27 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	process_unset(char *tmp2, t_enviro **enviro)
{
	t_enviro	*tmp;

	tmp = *enviro;
	while (tmp)
	{
		if (ft_searstr_unset(tmp2, tmp->value))
		{
			ft_remove_env(&tmp2, enviro, tmp->indice);
			break ;
		}
		tmp = tmp->next;
	}
}

int	ft_unset(char **unset, int ac, t_enviro **enviro)
{
	char	*tmp2;
	int		j;

	if (ac == 1)
		return (1);
	tmp2 = ft_echo(unset, enviro);
	if (!tmp2)
		return (0);
	j = 1;
	while (j < ac)
	{
		process_unset(tmp2, enviro);
		j++;
	}
	return (1);
}

void	ft_remove_env(char **unset, t_enviro **enviro, int indice)
{
	t_enviro	*tmp;
	t_enviro	*tmp_back;

	unset = unset;
	tmp = *enviro;
	tmp_back = NULL;
	while (tmp)
	{
		if (tmp->indice == indice)
		{
			if (tmp_back == NULL)
				*enviro = tmp->next;
			else
				tmp_back->next = tmp->next;
			if (tmp != NULL && tmp->value != NULL)
				free(tmp->value);
			if (tmp != NULL)
				free(tmp);
			tmp = NULL;
			return ;
		}
		tmp_back = tmp;
		tmp = tmp->next;
	}
}
