/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_quots.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:25:26 by aborges           #+#    #+#             */
/*   Updated: 2025/01/11 11:25:28 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_echo_quots(char **echo_quots, t_enviro **enviro)
{
	int			i;
	size_t		size;
	char		*value;

	if (!echo_quots[1])
		printf("\n");
	if (!echo_quots[1])
		return (NULL);
	value = NULL;
	i = 1;
	size = 0;
	while (echo_quots[i])
	{
		size += ft_strlen(echo_quots[i]);
		i++;
	}
	value = malloc(sizeof(char *) * size + ft_count(echo_quots) - 1);
	if (!value)
		return (NULL);
	i = 1;
	ft_echo_quots1(echo_quots, i, value);
	ft_echo_quots_aux(enviro, &value);
	free(value);
	return (result_echo_quots('\0', 0));
}
