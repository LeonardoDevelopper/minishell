/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:46:37 by lleodev           #+#    #+#             */
/*   Updated: 2024/10/29 08:56:13 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	verify_redirect_stdin(char *cmd)
{
	int		i;
	int		fd;
	char	**redirect;
	char	*trimed_str;

	i = 0;
	fd = -2;
	redirect = NULL;
	while (cmd[i])
	{
		if (cmd[i] == '<')
		{
			redirect = ft_split(cmd, '<');
			trimed_str = ft_strtrim(redirect[1], " ");
			fd = open(trimed_str, O_RDONLY);
			return (fd);
		}
		i++;
	}
	return (fd);
}



void	redirect_stdin(int fd, char *cmd, char *env[])
{
	int	pipe_fd[2];
	char	**full_cmd;
	char	*path;
	t_child_p	*child;

	pipe_fd[0] = fd;
	pipe_fd[1] = -1;
	child = new_child_p(pipe_fd);
	full_cmd = ft_split(cmd, ' ');
	if (child->pid == 0)
	{
		path = cmd_exist(full_cmd[0]);
		if (path)
		{
			dup2(fd, STDIN_FILENO);
			if (execve("/bin/cat", NULL, env) == -1) {
				perror("Erro ao executar execve");
				return ;
			}
			close(fd);
		}
	}
}








void	fun(void)
{
  int fd = open("Makefile", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Redireciona a entrada padrão para o arquivo
    dup2(fd, STDIN_FILENO);
    close(fd); // Fecha o descritor, pois `dup2` já o duplicou para STDIN

    // Define o comando e seus argumentos
    char *args[] = {"/bin/cat", NULL};  // O caminho pode ser apenas "cat" se o PATH estiver configurado
    char *envp[] = {NULL};

    // Executa o comando cat, que agora lerá a partir de "entrada.txt"
    if (execve("/bin/cat", args, envp) == -1) {
        perror("Erro ao executar execve");
        return 1;
    }
}
