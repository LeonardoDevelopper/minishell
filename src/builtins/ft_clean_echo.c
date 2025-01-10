/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:33:20 by aborges           #+#    #+#             */
/*   Updated: 2025/01/10 10:33:23 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**prepare_echo_args1(char *cmd)
{
	char	**mat;

	mat = malloc(sizeof(char *) * 3);
	if (!mat)
		return (NULL);
	mat[0] = strdup("echo");
	mat[1] = strdup(cmd);
	mat[2] = NULL;
	if (!mat[0] || !mat[1])
	{
		free(mat[0]);
		free(mat[1]);
		free(mat);
		return (NULL);
	}
	return (mat);
}

char	**handle_non_builtin1(char *cmd)
{
	char	**mat;

	mat = prepare_echo_args1(cmd);
	if (!mat)
		return (NULL);
	return (mat);
}

