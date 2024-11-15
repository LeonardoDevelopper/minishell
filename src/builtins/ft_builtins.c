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

void	ft_pwd(int ac)
{
	char	dir[1500];

	if (ac != 1)
	{
		printf("pwd: too many arguments\n");
		return ;
	}
	if (getcwd(dir, sizeof(dir)) != NULL)
		printf("%s\n", dir);
	else
		return ;
}

void	ft_env(int ac, char **env, t_enviro **enviro)
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
		printf("%s\n", list[i]);
		i--;
	}
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
}

void	ft_exit(char **end, int ac)
{
	(void)ac;
	if (ac > 1)
		printf ("there is 2 or more arg");
	if (!end)
		return ;
	rl_clear_history();
	exit (1);
}
