/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:42:02 by aborges           #+#    #+#             */
/*   Updated: 2024/10/17 15:05:23 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_check1(char **export, t_info **info, int j)
{
	t_info	*tmp;

	tmp = (t_info *)malloc(sizeof(t_info));
	if (!tmp)
		return ;
	tmp->indice = (*info)->indice + 1;
	tmp->value = (char *)malloc(sizeof(char) * (strlen(export[j]) + 1));
	if (!tmp->value)
	{
		free(tmp);
		return ;
	}
	ft_strcpy(tmp->value, export[j]);
	tmp->next = *info;
	*info = tmp;
}

void	export_check(char **export, int ac, t_info **info, int j)
{
	int	check;
	int	i;

	i = 0;
	while (export[j][i])
	{
		if (export[j][i] == '=' && export[j][i - 1] == '\0')
			printf("zsh: 43 not found\n");
		else if (export[j][i] && export[j][i + 1] == '=')
			check = 1;
		i++;
	}
	if (check == 1)
	{
		if (check_env(export, info, j) && j == ac)
			return ;
		else if (!check_env(export, info, j))
			export_check1(export, info, j);
	}
	else
	{
		printf("No\n");
	}
}

void	ft_export(char **export, int ac, t_info **info)
{
	int	j;

	if (ac == 1)
		ft_env(ac, export, info);
	else if (ac > 1)
	{
		j = 1;
		while (j < ac)
		{
			export_check(export, ac, info, j);
			j++;
		}
	}
}

int	check_env(char **export, t_info **info, int j)
{
	t_info	*tmp;
	int		check;
	char	*result;

	result = (char *)malloc(sizeof(char) * ft_strlen(export[j]) + 1);
	if (!result)
	{
		free(result);
		return (0);
	}
	ft_strcpy(result, export[j]);
	tmp = *info;
	check = 0;
	while (tmp)
	{
		if (ft_searstr(result, tmp->value))
		{
			check = 1;
			printf("existe\n");
			ft_replace_env(export, info, tmp->indice, j);
		}
		tmp = tmp->next;
	}
	free(result);
	return (check);
}

void	ft_replace_env(char **export, t_info **info, int indice, int j)
{
	t_info	*tmp;

	tmp = *info;
	while (tmp)
	{
		if (tmp->indice == indice)
		{
			free(tmp->value);
			tmp->value = (char *)malloc(sizeof(char) * (strlen(export[j]) + 1));
			if (!tmp->value)
				return ;
			ft_strcpy(tmp->value, export[j]);
			break ;
		}
		tmp = tmp->next;
	}
}
