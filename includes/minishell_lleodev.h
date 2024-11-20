/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lleodev.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:56:17 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/20 18:56:29 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_LLEODEV_H
# define MINISHELL_LLEODEV_H

//################################COLORS######################################

# define GREEN_TEXT "\033[1;32m"
# define RED_TEXT "\033[1;31m"
# define ORANGE_TEXT "\033[1;33m"
# define BLUE_TEXT "\033[1;34m"
# define GREEN_BG "\033[42m"
# define RED_BG "\033[41m"
# define ORANGE_BG "\033[43m"
# define BLUE_BG "\033[44m"
# define RESET "\033[0m"
# define CMD_NO_EXIST "This command is not recognized on this shell: "

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

typedef struct	s_prec
{
		int	num_args;
		char	*path;
		char	*input;
		char	*cmd;
		char	**args;
		t_redirect	*stdin_redirect;
		t_redirect	*stdout_redirect;
		int			stdout;
		int			stdin;
}		t_prec;

typedef struct	cmd_s
{
	t_child_p	*child;
	t_enviro		*enviro;
	void	*output;
	t_redirect	*redirect;
	int			cmd_num;
	char	*shell;
	char	*input;
	char	**args;
	char	**env;
	char	*full_path;
	char	**cmd_splited;
	t_prec	**precedence;
	char	*cmd;
}		t_cmd;

void	wait_p(int num);
void	run_multiple_cmd_test(t_cmd *cmd);
void	run_multiple_cmd(t_cmd *cmd);
void	run_cmd(t_cmd *cmd, char *env[]);
void	run_cmd_test(t_prec *prec, t_enviro **enviro, char *env[]);
void	*run_cmd_catch_output(char *cmd, t_enviro **enviro, char *env[]);
void	run_child_p(t_prec *prec, t_child_p *child, char *env[]);
void	*verify_redirect_stdin(char *cmd);
void    *verify_redirect_stdout(char *input);
void	redirect_stdin(t_cmd *cmd, char *env[]);
void	redirect_stdin_test(t_prec *prec, char *env[]);
void	print_args(t_cmd *cmd);
void	print_stdout_child(char *buffer);
void	run_child_p_test(char *path, char **args, t_child_p *child, char *env[]);
void	print_args(t_cmd *cmd);
char	**ft_split_del(char *str, char c);
char	**ft_split_args(char *str);
char	*ft_strjoin_matrix(char **mat, char c);
char	*display_shell(char *env[], char **tmp, t_enviro **enviro);
char	*cmd_exist(char *cmd);
char	**split_dir(void);
char	*read_stdout_child(int fd);
char	**catch_cmd_args(t_cmd *cmd);
char	*ft_strjoin_ptr(char *s1, char *s2);
char	*read_file(int fd);
char	*replace_char(char *str, char c, char rep);
char	*remove_end_char(char *str);
char	*remove_char(char *str, char c);
char	*remove_str(char *mat);
int	test_cmds(t_cmd *cmd);

int		**create_pipes(t_cmd *cmd);
int close_pipes(int **pipes, int pipe_num);
int		run_cmd_catch_output_test(t_prec *prec, t_enviro **enviro, char *env[]);
int		count_cmds_num(char *input);
int		count_rows_del(char *str, char c);
int		count_cmd_args(char *cmd);
int		count_rowss(char *str);
int		count_desk(char *str);
int		count_rows_splited(char **strstr);
int		d_quote(char *cmd);
int		verify_fd(t_redirect *redirec);
int		ft_strlen_c(char *str, char c);
int	cmd_exits(t_cmd *cmd);

t_child_p	*new_child_p(void *pipe);
t_prec	**split_cmds(char *input, int num_cmd);

void	free_matrix(char **matrix);

#endif
