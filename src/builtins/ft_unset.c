/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:43:38 by aborges           #+#    #+#             */
/*   Updated: 2024/10/10 08:43:39 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **unset, int ac, t_enviro **enviro)
{
	char		*tmp2;
	t_enviro	*tmp;
	int			j;

	if (ac == 1)
		return ;
	if (ac > 1)
	{
		j = 1;
		tmp2 = ft_echo(unset, enviro);
		if (!tmp2)
			return (0);
		while (j < ac)
		{
			tmp = *enviro;
			while (tmp)
			{
				if (ft_searstr_unset(tmp2, tmp->value))
				{
					ft_remove_env(unset, enviro, tmp->indice);
					break ;
				}
				tmp = tmp->next;
			}
			j++;
		}
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
