/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:27 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/20 19:06:37 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H


# include "../libft/libft.h"
# include <stdio.h> /* printf */
# include <unistd.h> /* write */
# include <sys/types.h> /* pid_t */
# include <readline/readline.h>

/* int	g_status; // Status de saída do comando executado mais recentemente */

/**
 * Estrutura que representa um comando minishell.
 * A estrutura t_shell contém informações sobre um comando mini, 
 * incluindo:
 * full_cmd -> Equivalente ao típico argv, contendo o nome do comando e seus
 * parâmetros quando necessário
 * full_path -> Se não for um builtin, primeiro disponível para o executável
 * indicado por argv[0] na variável PATH
 * infile -> Qual descritor de arquivo ler ao executar um comando (o padrão é stdin)
 * outfile -> Qual descritor de arquivo gravar ao executar um comando (o padrão é stdout)
 */
typedef struct s_shell
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
	struct s_shell *next;
}			t_shell;

/*(*
 * Estrutura que representa um prompt.
 * Contém informações relacionadas a um prompt incluindo:
 * *cmds -> Lista de comandos contendo um t_mini nó com todos os comandos
 * separados por pipes.
 * **envp -> Matriz atualizada contendo chaves e valores para o ambiente shell
 * pid -> ID do processo da instância do minishell
 */
typedef struct s_prompt
{
	t_shell	**cmds;
	char	**envp;
	pid_t	pid; 
}			t_prompt;

int	list_len(t_shell **stack);
# endif /* EXECUTOR_H */
