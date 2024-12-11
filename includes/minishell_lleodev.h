/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lleodev.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:56:17 by lleodev           #+#    #+#             */
/*   Updated: 2024/12/11 14:47:30 by lleodev          ###   ########.fr       */
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

typedef struct s_child_p
{
	int		pid;
	int		status;
	void	*pipe_fd;
}		t_child_p;

typedef struct s_redirect
{
	int	count;
	int	*fd_list;
}		t_redirect;

typedef struct s_prec
{
	int			num_args;
	int			builtins;
	int			stdout;
	int			stdin;
	char		*path;
	char		*input;
	char		*cmd;
	char		**args;
	t_redirect	*stdin_redirect;
	t_redirect	*stdout_redirect;
	t_child_p	*child;
}		t_prec;

typedef struct cmd_s
{
	int				cmd_num;
	char			*shell;
	char			*input;
	char			**env;
	t_enviro		*enviro;
	t_prec			**precedence;
}		t_cmd;

int			skip_space(char *cmd, int i);
int			skip_content_in_quote(char *input, int i);
int			handle_special_chr(char *input);
int			handle_redirect_token(char *input);
int			check_cmd_tokens(char *input);
int			ft_handle_tokens(char *input);
int			ft_handle_quotes(char *input);
int			handle_heredoc(char *del, char *name);
int			test_commands(t_cmd *cmd);
int			verify_dup_redirect_stdin(char *input);
int			close_pipes(int **pipes, int pipe_num);
int			count_cmds_num(char *input);
int			count_rows_del(char *str, char c);
int			count_rowss(char *str);
int			count_desk(char *str);
int			count_rows_splited(char **strstr);
int			verify_fd(t_redirect *redirec);
int			verify_dup_redirect_stdout(char *input);
int			verify_heredoc(char *input);
int			count_char(char *str, int c);
int			verify_quotes(char *input);
int			is_builtins(t_prec **prec);
int			check_builtins(t_prec *prec, t_enviro **enviro, char **env);
int			**create_pipes(t_cmd *cmd);

char		*handle_between_quotes(char *input);
char		*get_content_quotes(char *input);
char		*handle_literal(char *input);
char		*handle_no_literal(char *input);
char		*ft_strjoin_matrix(char **mat, char c);
char		*display_shell(char *env[], char **tmp, char **enviro);
char		*cmd_exist(char *cmd);
char		*read_stdout_child(int fd);
char		*catch_cmd_args(char *cmd);
char		*ft_strjoin_ptr(char *s1, char *s2);
char		*read_file(int fd);
char		*replace_char(char *str, char c, char rep);
char		*remove_end_char(char *str);
char		*remove_char(char *str, char c);
char		*remove_str(char *mat);
char		**split_dir(void);
char		**handle_double_quotes(char *input);
char		**ft_split_del(char *str, char c);
char		**ft_split_args(char *str);

void		fill_args(char **input);
void		print_args(t_cmd *cmd);
void		free_matrix(char **matrix);
void		initialize_cmd(t_cmd *cmd);
void		handle_args(t_prec *prec);
void		handle_cmd_exist(t_prec *prec);
void		handle_stdin(t_prec *prec);
void		free_prec(t_prec **prec);
void		free_cmd(t_cmd *cmd);
void		wait_p(int num);
void		handle_cmd(t_cmd *cmd);
void		run_multiple_cmd(t_cmd *cmd);
void		run_cmd(t_cmd *cmd, t_prec *prec);
void		print_stdout_child(char *buffer);
void		run_child_p(t_prec *prec, t_child_p *child, char *env[]);
void		handle_exit(t_cmd *cmd);
void		run_child_p_test(char *pth, char **ags, t_child_p *ch, char *env[]);
void		*try_open(t_redirect *redir, char *input, char *tmp);
void		*run_cmd_catch_output(char *cmd, char *env[]);
void		*verify_redirect_stdin(char *cmd);
void		*verify_redirect_stdout(char *input);

t_prec		**split_cmds(char *input, int num_cmd);
t_prec		*initialize_prec(void);
t_child_p	*new_child_p(void *pipe);
t_redirect	*initialize_redirect(void);

#endif
