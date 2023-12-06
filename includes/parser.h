/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:27 by faaraujo          #+#    #+#             */
/*   Updated: 2023/12/06 18:36:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libft/libft.h"
# include <stdio.h> /* printf */
# include <unistd.h> /* write */
# include <sys/types.h> /* pid_t */
# include <readline/readline.h>
# include <readline/history.h>

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
}			t_shell;

/**
 * Estrutura que representa um prompt.
 * Contém informações relacionadas a um prompt incluindo:
 * *cmds -> Lista de comandos contendo um t_mini nó com todos os comandos
 * separados por pipes.
 * **envp -> Matriz atualizada contendo chaves e valores para o ambiente shell
 * pid -> ID do processo da instância do minishell
 */
typedef struct s_prompt
{
	t_shell	*cmds;
	char	**envp;
	pid_t	pid; 
}			t_prompt;

/**
 * LEXER
 * @brief Depois de ler, stdin usamos uma função que nomeada cmdtrim que 
 * separa a string levando em consideração espaços e aspas. 
 * Por exemplo:
 * string: echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * output: {echo, "hello      there", how, are, 'you 'doing?, $USER, |wc, -l, >outfile, NULL}
*/

/**
 * EXPANDER
 * @brief seguida, aplicamos as funções expansoras em cima de cada substring
 * da string original, resultando em algo semelhante a isto:
 * output: {echo, "hello      there", how, are, 'you 'doing?, faleite, |wc, -l, >outfile, NULL}
 * Nota: se uma variável não for encontrada, a parte $var da string será
 * substituída por uma string vazia
*/

/**
 * PIPE & REDIRECT
 * @brief Por último, temos outra função de divisão chamada cmdsubsplit que
 * separa com <, |, ou >, mas apenas se esses caracteres estiverem fora das 
 * aspas:
 * output: {echo, "hello      there", how, are, 'you 'doing?, pixel, |, wc, -l, >, outfile, NULL}
*/

# endif /* PARSER_H */