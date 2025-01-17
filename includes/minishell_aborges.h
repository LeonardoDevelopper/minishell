/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_aborges.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:57:12 by aborges           #+#    #+#             */
/*   Updated: 2025/01/15 11:04:15 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ABORGES_H
# define MINISHELL_ABORGES_H

typedef struct s_enviro
{
	int				indice;
	char			*value;
	struct s_enviro	*next;
}	t_enviro;

int		ft_count(char **str);
int		ft_type_caracter(char c);

char	*ft_toupper_str(char *str);
char	**ft_split_path(char *path);
int		ft_listsize(t_enviro **enviro);
int		ft_searstr(char *s1, char *s2);
void	ft_strcpy(char *dst, char *src);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strjoin_space(char *s1, char *s2);

char	**fill_max(t_enviro **enviro);
void	print_env(char **env, int fd);
int		fill_env(t_enviro **enviro, char **env);
void	print_list_env(char **list, int fd, int i);
char	*search_env(char *world, t_enviro **enviro);
int		ft_cd(char **cd, int ac, t_enviro **enviro);
int		check_env(char **export, t_enviro **enviro, int j);

void	ft_new_pwd(char **pwd, t_enviro **enviro);
void	free_cd(char **pwd, char **oldpwd);
void	export_check(char **export, int ac, t_enviro **enviro, int j);
void	ft_env_export(int ac, char **env, t_enviro **enviro);

//builtin function echo
int		case_n(char *str);
int		ft_check_cots(char **str);
char	**ft_split_echo(char *str);
char	*result_echo(int c, int reset);
char	**prepare_echo_args1(char *cmd);
char	**handle_non_builtin1(char *cmd);
char	*ft_echo(char **echo, t_enviro **enviro);
void	case_redirect(char **echo, char *value, int *var);
void	check_dolar(char **result, int i, int *j);
char	*create_aux_string(char *echo_indice, int i);
void	fill_str(char *str);
void	free_env_mat(char **mat);
void	free_enviro_list(t_enviro **enviro);
int		ft_pwd(int fd);
void	ft_env(int ac, char **env, t_enviro **enviro, int fd);
void	ft_exit(char **end, int ac, t_enviro **enviro, int fd);
void	init_status(t_enviro **enviro, int value);

void	aux_cmpecho(char *aux, t_enviro *tmp);
void	check_single_quotes(char *str, int *j);
void	ft_echo1(char **echo, int i, char *value);
void	resave(char *str, t_enviro **enviro, int i);
void	double_asp(char *str, t_enviro **enviro, int i);
void	check_echo(char **result, t_enviro **enviro, int i);
void	check_double_quotes(char *str, t_enviro **enviro, int *j);
void	expandecho(char **echo, t_enviro **enviro, int indice, int i);

//export funcion
int		ft_export(char **export, int ac, t_enviro **enviro);
void	handle_export_loop(char **export, int ac, t_enviro **enviro);
void	ft_remove_env(char **unset, t_enviro **enviro, int indice);
void	ft_replace_env(char **export, t_enviro **enviro, int indice, int j);

//unset function
int		ft_searstr_unset(char *s1, char *s2);
int		ft_unset(char **unset, int ac, t_enviro **enviro);

//comand function
void	ft_signal(void);
void	ft_signal_value(int signal_value);
int		ft_execute(char **cmd, int ac, char **env, t_enviro **enviro);
int		execute_cmd(char **cmd, int ac, t_enviro **enviro, char **env);

//NEW ECHO
void	ft_echo_quots_aux(t_enviro **enviro, char **value);
char	*result_echo_quots(int c, int reset);
char	*ft_echo_quots(char **echo_quots, t_enviro **enviro);
void	aux_check_echo_quots(char **result, t_enviro **enviro, int i, int *j);
void	check_echo_quots(char **result, t_enviro **enviro, int i);
void	aux_cmpecho_quots(char *aux, t_enviro *tmp);
char	*create_aux_string_quots(char *echo_quots_indice, int i);
void	expandecho_quots(char **echo_quots,
			t_enviro **enviro, int indice, int i);
void	ft_echo_quots1(char **echo_quots, int i, char *value);
void	check_single_quotes1(char *str, int *j);
void	check_double_quotes1(char *str, t_enviro **enviro, int *j);
void	double_asp_quots(char *str, t_enviro **enviro, int i);
void	resave_quots(char *str, t_enviro **enviro, int i);
int		ft_check_cots_quots(char **str);
void	check_dolar_quots(char **result, int i, int *j);
void	case_redirect_quots(char **echo, char *value, int *var);

#endif
