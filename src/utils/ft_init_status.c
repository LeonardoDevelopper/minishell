/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:17:58 by aborges           #+#    #+#             */
/*   Updated: 2025/01/08 13:18:00 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**allocate_status(void)
{
	char	**status;

	status = malloc(sizeof(char *) * 3);
	if (!status)
		return (NULL);
	status[0] = malloc(sizeof(char) * 240);
	if (!status[0])
	{
		free(status);
		return (NULL);
	}
	status[1] = malloc(sizeof(char) * 250);
	if (!status[1])
	{
		free(status[0]);
		free(status);
		return (NULL);
	}
	status[2] = NULL;
	return (status);
}

static void	free_status(char **status)
{
	free(status[1]);
	free(status[0]);
	free(status);
}

static char	*create_export_string(int value)
{
	int		n;
	char	*str_itoa;
	char	*str_join;

	if (value < 0)
		n = value + 255;
	else
		n = value % 255;
	str_itoa = ft_itoa(n);
	if (!str_itoa)
		return (NULL);
	str_join = ft_strjoin("?=", str_itoa);
	free(str_itoa);
	return (str_join);
}

void	init_status(t_enviro **enviro, int value)
{
	char	**status;
	char	*str_join;

	status = allocate_status();
	if (!status)
		return ;
	ft_strcpy(status[0], "export");
	str_join = create_export_string(value);
	if (!str_join)
	{
		free_status(status);
		return ;
	}
	ft_strcpy(status[1], str_join);
	ft_export(status, ft_count(status), enviro);
	free(str_join);
	free_status(status);
}
