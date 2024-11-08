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

void	ft_unset(char **unset, int ac, t_enviro **enviro)
{
	t_enviro	*tmp;
	int			j;

	if (ac == 1)
		return ;
	if (ac > 1)
	{
		j = 1;
		while (j < ac)
		{
			tmp = *enviro;
			while (tmp)
			{
				if (ft_searstr_unset(unset[j], tmp->value))
				{
					printf("existe indice: %d\n", tmp->indice);
					ft_remove_env(unset, enviro, tmp->indice);
				}
				tmp = tmp->next;
			}
			j++;
		}
	}
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
			free(tmp->value);
			free(tmp);
			return ;
		}
		tmp_back = tmp;
		tmp = tmp->next;
	}
}
