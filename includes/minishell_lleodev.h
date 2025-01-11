/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lleodev.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:10:48 by lleodev           #+#    #+#             */
/*   Updated: 2025/01/11 15:15:36 by lleodev          ###   ########.fr       */
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

typedef struct s_tmp
{
	char	*tmp;
	char	**tmp2;
}		t_tmp;

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
	t_child_p	*child;
	t_redirect	*stdin_redirect;
	t_redirect	*stdout_redirect;
}		t_prec;

typedef struct cmd_s
{
	int				cmd_num;
	char			*shell;
	char			*input;
	char			*cmd_splited;
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
int			count_rows_splited(char **strstr);
int			verify_fd(t_redirect *redirec);
int			verify_dup_redirect_stdout(char *input);
int			verify_heredoc(char *input);
int			count_char(char *str, int c);
int			verify_quotes(char *input);
int			is_builtins(t_prec **prec);
int			check_builtins(t_prec *prec, t_enviro **enviro, char **env);
int			in_quotes(int in);
int			cpy_args(char *dst, char *src, int j);
int			count_char(char *str, int c);
int			skip_space(char *cmd, int i);
int			check_cmd_token_end(char *str);
int			**create_pipes(t_cmd *cmd);
int			cancel_heredoc(char *dir);
int			ft_strcpy_custom(int begin, char *dest, char *src);
int			handle_exit(t_cmd *cmd);
int			dup_tokens_followed(char *n, int i, int len);
int			count_rows(char **mat);
int			count_cmds_num(char *input);
int			first_quote(char *tmp);

char		*ft_expand(t_cmd *cmd, t_prec *prec);
char		*handle_between_quotes(char *input, int first);
char		*get_content_quotes(char *input, int first);
char		*handle_literal(char *input);
char		*handle_no_literal(char *input);
char		*ft_strjoin_matrix(char **mat, char c);
char		*display_shell(char *env[], char **tmp);
char		*display_shell2(char *envp[], char **tmp_tmp);
char		*cmd_exist(t_cmd *s_cmd, char *cmd);
char		*read_stdout_child(int fd);
char		*catch_cmd_args(char *cmd, char *tmp, int first);
char		*ft_strjoin_ptr(char *s1, char *s2);
char		*replace_char(char *str, char c, char rep);
char		*expand_tokens(char *input, int first);
char		*remove_end_char(char *str);
char		*remove_char(char *str, char c);
char		*remove_str(char *mat);
char		*desk_to_space(char *input);
char		**split_dir(t_cmd *cmd);
char		**handle_double_quotes(char *input);
char		**ft_split_del(char *str, char c);
char		**ft_split_args(char *str);
char		**original_env(char *path_cpy, char **path);
char		**aborges_env(t_cmd *cmd, char *path_cpy, char **path);

void		remove_old_file(char *dir);
void		free_two(char *tmp, char **tmp2);
void		execbin(t_cmd *cmd, t_prec *prec);
void		change_input_output(int i, int num, int **pipes, t_prec *prec);
void		replace_in_quotes(char *dest, char *src, int index1, int index2);
char		**fill_args(char **input);
void		print_args(t_cmd *cmd);
void		free_matrix(char **matrix);
void		free_pipe(int **pipe);
void		initialize_cmd(t_cmd *cmd);
void		handle_args(t_prec *prec);
void		handle_cmd_exist(t_cmd *cmd, t_prec *prec);
void		*handle_stdin(t_prec *prec);
void		create_dir(char *dir);
void		handle_stdout(t_prec *prec);
void		free_prec(t_prec **prec);
void		free_cmd(t_cmd *cmd);
void		wait_p(t_cmd *cmd, int num);
void		handle_cmd(t_cmd *cmd);
void		run_multiple_cmd(t_cmd *cmd);
void		run_cmd(t_cmd *cmd, int **pipes, int i);
void		print_stdout_child(char *buffer);
void		run_child_p(t_prec *prec, t_child_p *child, char *env[]);
void		run_child_p_test(char *pth, char **ags, t_child_p *ch, char *env[]);
void		*try_open(t_redirect *redir, char *input, char *tmp);
void		*run_cmd_catch_output(char *cmd, char *env[]);
void		*verify_redirect_stdin(char *cmd);
void		*verify_redirect_stdout(char *input);
void		change_builtins_output(t_cmd *cmd, int **pipes, int i);
void		free_left(char *trimmed_str, t_cmd *cmd);
void		free_left2(char *trimmed_str, t_cmd *cmd);
void		print_chech_builtin(t_prec *prec);

t_prec		*initialize_prec(void);
t_prec		**split_cmds(t_cmd *cmd, char *input, int num_cmd);

t_child_p	*new_child_p(void *pipe);

t_redirect	*initialize_redirect(void);

t_cmd		*initialize_prompt(int argc, char *argv[], char *envp[]);

#endif
