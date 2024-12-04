/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:27:11 by aborges           #+#    #+#             */
/*   Updated: 2024/12/03 13:21:24 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (str[i] == c)
			counter++;
		i++;
	}
	if (!counter)
		return (str);
	new = (char *)malloc(sizeof(char ) * ((ft_strlen(str) - counter) + 1));
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			new[j++] = str[i++];
		else
			i++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
		while (matrix[i])
		{
			free(matrix[i]);
			matrix[i] = NULL;
			i++;
		}
		free(matrix);
		matrix = NULL;
}

char	*ft_variadic_strjoin(char *str, ...)
{
	
}

int	count_mat_char(char **mat)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			size++;
			j++;
		}
		size += 1;
		i++;
	}
	return (size);
}
char	*ft_strjoin_matrix(char **mat, char c)
{
	int	i;
	int	j;
	int	k;
	int	size;
	char	*new_str;

	i = 0;
	k = 0;
	new_str = (char *)malloc(sizeof(char ) * (1024));
	if (!new_str)
		return (NULL);
	while (mat[i])
	{
		j = 0;
		while (mat[i][j])
		{
			new_str[k] = mat[i][j];
			j++;
			k++;
		}
		new_str[k++] = c;
		i++;
	}
	new_str[k] = '\0';
	return (new_str);
}

char	*remove_str(char *str)
{
	char	**mat1;
	char	**mat2;
	static char	res[1024];
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	mat1 = ft_split(str, ' ');
	while (mat1[i])
	{
		mat2 = ft_split(mat1[i], '<');
		j = 0;
		while (mat2[j])
		{
			printf("\n%s", mat2[j]);
			j++;
		}
		i++;
	}
}
