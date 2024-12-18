/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:19:31 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/13 15:58:03 by lleodev          ###   ########.fr       */
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

#define SHELL_1 "\001\033[1;36m\033[1;33m\002┌───("
#define SHELL_2 "\001\033[1;35m\002᯽ \001\033[1;32m\002"
#define SHELL_3 "\001\033[1;34m\002)⸺ [\001\033[1;34m\033[1;37m\002~"
#define SHELL_4 "\001\033[1;34m\002]\001\033[0m\002\n\001\033[1;32m\033[1;36m\033[1;33m\002└──$ \001\033[0m\002"
#define SHELL_4_2 "\001\033[1;34m\002]\001\033[0m\002"

#endif
