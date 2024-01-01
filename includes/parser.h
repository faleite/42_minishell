/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:27 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/01 14:02:23 by faaraujo         ###   ########.fr       */
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
# include <stdlib.h> /* getenv */
# include <limits.h>
# include <signal.h> /* */
# include <sys/ioctl.h> /* */
# include <fcntl.h> /* open */

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
	char			**full_cmd;
	char			*full_path;
	int				infile;
	int				outfile;
	struct s_shell	*next;
}					t_shell;

/**
 * Estrutura que representa um prompt.
 * Contém informações relacionadas a um prompt incluindo:
 * *cmds -> Lista de comandos contendo um t_shell nó com todos os comandos
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

/* Utils */
void	print_arr(char **arr);
void	free_arr(char **arr);

/* Lexer */
int		dollar(char **src, char **dst, int i);
int		outside_quotes(char **s2, char **s3, int i);
int		inside_dbquotes(char **s1, char **s2, int i, char *sig);
int		inside_spquotes(char **s1, char **s2, int i, char *sig);
char	*expander_inside(char *s1);
char	*expander_outside(char *s2);
char	**strtrim_quotes(char **arr);
void	handle_quotes(char *s1, char *s2);
void	replace_spaces(char *s1);

/* Parser */
t_shell	*cmd(void);

/* Signals */
// void	ctrlc_sigint(int sig);

extern int	g_status;

#endif /* PARSER_H */