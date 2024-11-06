/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:56:17 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/11 09:58:04 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LLEODEV_H
# define MINISHELL_LLEODEV_H

//################################COLORS######################################

#define GREEN_TEXT "\033[1;32m"
#define RED_TEXT "\033[1;31m"
#define ORANGE_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[1;34m"
#define GREEN_BG "\033[42m"
#define RED_BG "\033[41m"
#define ORANGE_BG "\033[43m"
#define BLUE_BG "\033[44m"
#define RESET "\033[0m"

typedef struct	s_child_p
{
	int	pid;
	void	*pipe_fd;
	int	status;
}		t_child_p;

void	run_cmd(char *cmd, t_enviro **enviro, char *env[]);
void	*run_cmd_catch_output(char *cmd, t_enviro **enviro, char *env[]);
void	run_child_p(char *cmd, char **abs_path, t_child_p *child, char *env[]);
void	print_stdout_child(char *buffer);
char	*display_shell(char *env[], char **tmp, t_enviro **enviro);
char	*cmd_exist(char *cmd);
char	**split_dir(void);
char	*read_stdout_child(int fd);
int		count_desk(char *str);
int		d_quote(char *cmd);
int	verify_redirect_stdin(char *cmd);
char	*read_file(int fd);
char	*redirect_stdin(char *cmd);

int	ft_strlen_c(char *str, char c);
char	*ft_strjoin_ptr(char *s1, char *s2);
char	*replace_char(char *str, char c, char rep);
char	*remove_end_char(char *str);

t_child_p	*new_child_p(void *pipe);

void	free_matrix(char **matrix);

#endif
