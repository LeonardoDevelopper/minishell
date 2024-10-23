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

void	ft_unset(char **unset, int ac, t_info **info)
{
	t_info	*tmp;
	int		j;

	if (ac == 1)
		return ;
	if (ac > 1)
	{
		j = 1;
		while (j < ac)
		{
			tmp = *info;
			while (tmp)
			{
				if (ft_searstr_unset(unset[j], tmp->value))
				{
					printf("existe indice: %d\n", tmp->indice);
					ft_remove_env(unset, info, tmp->indice);
				}
				tmp = tmp->next;
			}
			j++;
		}
	}
}

void	ft_remove_env(char **unset, t_info **info, int indice)
{
	t_info	*tmp;
	t_info	*tmp_back;
	(void)unset;
	tmp = *info;
	tmp_back = NULL;
	while (tmp)
	{
		if (tmp->indice == indice)
		{
			if (tmp_back == NULL)
				*info = tmp->next;
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
