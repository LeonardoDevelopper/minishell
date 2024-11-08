/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_enviro.c                                     :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:05:23 by aborges           #+#    #+#             */
/*   Updated: 2024/10/31 16:05:53 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_enviro_list(t_enviro **enviro)
{
	t_enviro	*tmp;

	while (*enviro)
	{
		tmp = (*enviro)->next;
		free((*enviro)->value);
		free(*enviro);
		*enviro = tmp;
	}
}
