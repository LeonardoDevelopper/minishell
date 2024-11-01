/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:05:23 by aborges           #+#    #+#             */
/*   Updated: 2024/10/31 16:05:53 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_info_list(t_info **info)
{
	t_info	*tmp;

	while (*info)
	{
		tmp = (*info)->next;
		free((*info)->value);
		free(*info);
		*info = tmp;
	}
}
