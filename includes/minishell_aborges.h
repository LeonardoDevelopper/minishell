/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <aborges@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:57:12 by aborges           #+#    #+#             */
/*   Updated: 2024/10/23 12:27:16 by aborges          ###   ########.fr       */
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

//auxi function // libft
int		ft_count(char **str);
char	**ft_split_echo(char *str);//UNIFICAR
//char	**ft_split(char *str);
char	*ft_toupper_str(char *str);
int		ft_listsize(t_enviro **enviro);
char	**ft_split_path(char *path);
int		ft_searstr(char *s1, char *s2);
void	ft_strcpy(char *dst, char *src);
//char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strjoin_space(char *s1, char *s2);

//builtin function
void	ft_ls(int ac);
void	ft_pwd(int ac);
void	ft_clear(int ac);
void	ft_cd(char **cd, int ac);
void	ft_exit(char **end, int ac);
int		fill_env(t_enviro **enviro, char **env);
void	ft_env(int ac, char **cmd, t_enviro **enviro);
void	ft_echo(char **echo, int ac, t_enviro **enviro);
int		check_env(char **export, t_enviro **enviro, int j);

//echo function
void	aux_cmpecho(char *aux, t_enviro *tmp);
void	ft_echo(char **echo, int ac, t_enviro **enviro);
void	auxecho(char **echo, t_enviro **enviro, int indice);
void	expandecho(char **echo, t_enviro **enviro, int	indice);

//export funcion
void	ft_export(char **export, int ac, t_enviro **enviro);
void	ft_remove_env(char **unset, t_enviro **enviro, int indice);
void	ft_replace_env(char **export, t_enviro **enviro, int indice, int j);

//unset function
int		ft_searstr_unset(char *s1, char *s2);
void	ft_unset(char **unset, int ac, t_enviro **enviro);

//main function
int		check_arg(char *arg, t_enviro **enviro, char **env);

//comand function
void	ft_signal(void);
void	ft_ctrld(char *input);
void	ft_signal_value(int signal_value);
int		ft_redirect(char **cmd, int ac, t_enviro **enviro, char **env);
int		check_builtins(char **cmd, t_enviro **enviro, char **env);
int		ft_execute(char **cmd, int ac, char **env, t_enviro **enviro);
int		execute_cmd(char **cmd, int ac, t_enviro **enviro, char **env);

//redition
int		open_file(const char *filename, int flags, mode_t mode);

//free function
void	free_result(char **result);

#endif
