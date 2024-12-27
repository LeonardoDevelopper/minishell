/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:27:11 by aborges           #+#    #+#             */
/*   Updated: 2024/12/15 14:02:48 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_ptr(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (len == 0)
		return (NULL);
	res = (char *)malloc(sizeof(char ) * (len + 1));
	res[len] = '\0';
	i = -1;
	while (s1 != NULL && s1[++i] != '\0')
		res[i] = s1[i];
	if (s1 != NULL)
		free(s1);
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
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
		else
			res[i] = str[i];
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
	while (i < (ft_strlen(str) - 1))
	{
		res[i] = str[i];
		i++;
	}
	if (str)
		free(str);
	return (res);
}

int	count_rows_splited(char **strstr)
{
	int	i;

	i = 0;
	while (strstr[i])
		i++;
	return (i);
}

char	*remove_char(char *str, char c)
{
	int		i;
	int		j;
	int		counter;
	char	*new;

	i = 0;
	j = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i++] == c)
			counter++;
	}
	if (!counter)
		return (str);
	new = (char *)malloc(sizeof(char ) * ((ft_strlen(str) - counter) + 1));
	i = -1;
	while (str[++i])
	{
		if (str[i] != c)
			new[j++] = str[i++];
	}
	if (str != NULL)
		free(str);
	return (new[j] = '\0', new);
}
