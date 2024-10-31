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
	int	status;
	void	*pipe_fd;
}		t_child_p;

typedef struct	s_redirect
{
	int	count;
	int	*fd_list;
}		t_redirect;

typedef struct	s_cmd
{
	t_child_p	*child;
	t_info		*info;
	t_redirect	*redirect;
	void	*output;
	char	*shell;
	char	*input;
	char	**args;
	char	*full_path;
	char	*cmd;
}		t_cmd;

void	run_cmd(char *cmd, t_info **info, char *env[]);
void	*run_cmd_catch_output(char *cmd, t_info **info, char *env[]);
void	run_child_p(char *cmd, char **abs_path, t_child_p *child, char *env[]);
void	print_stdout_child(char *buffer);
char	*display_shell(char *env[], char **tmp, t_info **info);
char	*cmd_exist(char *cmd);
char	**split_dir(void);
char	*read_stdout_child(int fd);
int	count_cmd_args(char *cmd);
char	**catch_cmd_args(char *cmd);

int		count_desk(char *str);
int		d_quote(char *cmd);
void	*verify_redirect_stdin(char *cmd);
char	*read_file(int fd);
void	redirect_stdin(t_redirect *redirec, char *cmd, char *env[]);
int	verify_fd(t_redirect *redirec);
int	ft_strlen_c(char *str, char c);
char	*ft_strjoin_ptr(char *s1, char *s2);
char	*replace_char(char *str, char c, char rep);
char	*remove_end_char(char *str);

t_child_p	*new_child_p(void *pipe);

void	free_matrix(char **matrix);

#endif
