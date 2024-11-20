/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleodev <lleodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:17:13 by lleodev           #+#    #+#             */
/*   Updated: 2024/11/20 11:01:02 by lleodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_CMDS 5 // Número máximo de comandos (ajuste conforme necessário)

void execute_pipeline(char *commands[][3], int n_cmds) {
    int pipes[MAX_CMDS - 1][2];
    pid_t pid;
    int i;

    // Cria os pipes necessários
    for (i = 0; i < n_cmds - 1; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < n_cmds; i++) {
        pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            // Processo filho
            if (i > 0) {
                // Se não for o primeiro comando, redireciona a entrada para o pipe anterior
                dup2(pipes[i - 1][0], STDIN_FILENO);
            }
            if (i < n_cmds - 1) {
                // Se não for o último comando, redireciona a saída para o pipe atual
                dup2(pipes[i][1], STDOUT_FILENO);
            }

            // Fecha todos os pipes no filho
            for (int j = 0; j < n_cmds - 1; j++) {
                close(pipes[j][0]);
                close(pipes[j][1]);
            }

            // Executa o comando
            execvp(commands[i][0], commands[i]);
            perror("execvp"); // Apenas ocorre em caso de erro
            exit(EXIT_FAILURE);
        }
    }

    // Processo pai
    // Fecha todos os pipes
    for (i = 0; i < n_cmds - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Espera por todos os processos filhos
    for (i = 0; i < n_cmds; i++) {
        wait(NULL);
    }
}

int main(int argc, char **argv) {
    // Defina os comandos e argumentos
    char *commands[][3] = {
        {"cat", "Makefile", NULL},    // Primeiro comando
        {"grep", "lleodev", NULL},  // Segundo comando
        {"wc", "-l", NULL}     // Terceiro comando
    };

    int n_cmds = sizeof(commands) / sizeof(commands[0]);

    // Executa o pipeline
    execute_pipeline(commands, n_cmds);

    return 0;
}



fun()
{
			
		for (i = 0; i <= cmd->cmd_num; i++) {
			pid = fork();
			if (pid == -1) {
				perror("fork");
				exit(EXIT_FAILURE);
			}

			if (pid == 0) {
				// Processo filho
				if (i > 0) {
					// Se não for o primeiro comando, redireciona a entrada para o pipe anterior
					dup2(pipes[i - 1][0], STDIN_FILENO);
				}
				if (i <= cmd->cmd_num - 1) {
					// Se não for o último comando, redireciona a saída para o pipe atual
					dup2(pipes[i][1], STDOUT_FILENO);
				}

				// Fecha todos os pipes no filho
				for (int j = 0; j <= cmd->cmd_num - 1; j++) {
					close(pipes[j][0]);
					close(pipes[j][1]);
				}

				// Executa o comando
				execve(cmd->precedence[i]->path, cmd->precedence[i]->args, cmd->args);
				perror("execve"); // Apenas ocorre em caso de erro
				exit(EXIT_FAILURE);
			}
		}

		// Processo pai
		// Fecha todos os pipes
		for (i = 0; i <= cmd->cmd_num - 1; i++) {
			close(pipes[i][0]);
			close(pipes[i][1]);
		}

		// Espera por todos os processos filhos
		for (i = 0; i <= cmd->cmd_num; i++) {
			wait(NULL);
		}    
}