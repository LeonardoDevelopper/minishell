/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:45:28 by aborges           #+#    #+#             */
/*   Updated: 2024/10/23 10:26:16 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(int ac, int fd)
{
	ac = ac;
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
		//printf("env: ‘%s’: No such file or directory\n", env[1]);
		ft_putstr_fd("env: ", fd);
		ft_putstr_fd(env[1], fd);
		ft_putstr_fd(": No such file or directory", fd);
		printf("\n");
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
		if (ft_searstr(list[i], "?=") == NULL)
		{
			ft_putstr_fd(list[i], fd);
			printf("\n");
		}
			//printf("%s\n", list[i]);
		i--;
	}
}

void	ft_env_export(int ac, char **env, t_enviro **enviro, int fd)
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
		if (ft_searstr(list[i], "?=") == NULL)
		{
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(list[i], fd);
			printf("\n");
		}
			//printf("declare -x %s\n", list[i]);
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
}

void	ft_exit(char **end, int ac, t_enviro **enviro, int fd)
{
	if (ac > 1)
		exit(ft_atoi(end[1]));
	if (end)
		rl_clear_history();
	exit(0);
}
