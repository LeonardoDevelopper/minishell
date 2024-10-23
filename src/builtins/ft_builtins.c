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

void	ft_env(int ac, char **env, t_info **info)
{
	int		i;
	t_info	*tmp;
	char	*list[1000];

	if (ac > 1)
	{
		printf("env: ‘%s’: No such file or directory\n", env[1]);
		return ;
	}
	tmp = *info;
	i = 0;
	while (tmp)
	{
		list[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	i = ft_listsize(info) - 1;
	while (i >= 0)
	{
		printf("%s\n", list[i]);
		i--;
	}
}

void	ft_cd(char **cd, int ac)
{
	char	*home;

	home = getenv("HOME");
	if (ac == 1)
	{
		if (!home)
			return ;
		if (chdir(home) == -1)
			printf("cd: string not in pwd\n");
	}
	else if (ac == 2)
	{
		if (chdir(cd[1]) == -1)
			printf("cd: string not in %s\n", cd[1]);
	}
	else
		return ;
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
