/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:19:31 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/23 13:19:34 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "libft.h"
# include "minishell_aborges.h"
# include "minishell_lleodev.h"

#define SHELL_1 "\033[1;36m\033[1;33m┌───⸨"

#define SHELL_2 "\033[1;35m᯽ \033[1;32m"
#define SHELL_3 "\033[1;34m⸩⸺  [\033[1;34m\033[1;37m~/"

#define SHELL_4 "\033[1;34m]\033[0m\n\033[1;32m\033[1;36m\033[1;33m└──$ \033[0m"

#endif
