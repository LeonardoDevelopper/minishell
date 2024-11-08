/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:27:11 by aborges           #+#    #+#             */
/*   Updated: 2024/11/08 10:27:16 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_c(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c)
		len++;
	return (len);
}

char	*ft_strjoin_ptr(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	j = 0;
	if (s1)
		len = ft_strlen(s1) + ft_strlen(s2);
	else
		len = ft_strlen(s2);
	res = (char *)malloc(sizeof(char ) * (len + 1));
	res[len] = '\0';
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[j])
		res[i++] = s2[j++];
	return (res);
}

char	*replace_char(char *str, char c, char rep)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof (char ) * ft_strlen(str) + 1);
	res[ft_strlen(str)] = '\0';
	while (str[i])
	{
		if (str[i] == c)
			res[i] = rep;
		i++;
	}
	free(str);
	return (res);
}

char	*remove_end_char(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char ) * (ft_strlen(str)));
	res[ft_strlen(str) - 1] = '\0';
	while (str[i + 1])
	{
		res[i] = str[i];
		i++;
	}
	if (str)
		free(str);
	return (res);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}
