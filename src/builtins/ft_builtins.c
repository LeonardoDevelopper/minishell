/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:45:28 by aborges           #+#    #+#             */
/*   Updated: 2025/01/09 12:05:16 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(int fd)
{
	char	dir[1500];

	if (getcwd(dir, sizeof(dir)) == NULL)
		return (0);
	else
	{
		ft_putstr_fd(dir, fd);
		printf("\n");
		return (1);
	}
}

void	ft_env(int ac, char **env, t_enviro **enviro, int fd)
{
	int			i;
	t_enviro	*tmp;
	char		*list[1000];

	if (ac > 1)
	{
		print_env(env, fd);
		return ;
	}
	tmp = *enviro;
	i = 0;
	while (tmp)
	{
		list[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	i = ft_listsize(enviro) - 1;
	print_list_env(list, fd, i);
}

void	ft_env_export(int ac, char **env, t_enviro **enviro)
{
	int			i;
	t_enviro	*tmp;
	char		*list[1000];

	if (ac > 1)
	{
		printf("env: ‘%s’: No such file or directory\n", env[1]);
		return ;
	}
	tmp = *enviro;
	i = 0;
	while (tmp)
	{
		list[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	i = ft_listsize(enviro) - 1;
	while (i >= 0)
	{
		if (ft_searstr(list[i], "?=") == 0)
			printf("declare -x %s\n", list[i]);
		i--;
	}
}

char	*search_env(char *world, t_enviro **enviro)
{
	t_enviro	*tmp;

	tmp = *enviro;
	while (tmp)
	{
		if (ft_searstr(world, tmp->value))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_exit(char **end, int ac, t_enviro **enviro, int fd)
{
	enviro = enviro;
	fd = fd;
	if (ac > 1)
		exit(ft_atoi(end[1]));
	if (end)
		rl_clear_history();
	free_matrix(end);
	exit(0);
}
