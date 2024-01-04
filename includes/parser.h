/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:27 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/04 21:13:11 by faaraujo         ###   ########.fr       */
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

# define PIPE "|"
# define INPUT_REDIRECT "<"
# define OUTPUT_REDIRECT ">"
# define APPEND ">>"
# define HERE_DOC "<<"

typedef enum	e_token
{
	INPUT_ID = 1,
	OUTPUT_ID,
	HEREDOC_ID,
	APPEND_ID,
	PIPE_ID,
	ARGS_ID,
}		t_enum_tokens;

typedef	struct s_redirect
{
	t_enum_tokens	token_id;
	char			*file;
	struct s_redirect	*next;
}					t_redirect;

/**
 * @brief Estrutura que representa um comando minishell.
 * incluindo:
 * @param cmd Se não for um builtin, primeiro disponível para o executável
 * indicado por argv[0] na variável PATH
 * @param args Equivalente ao típico argv, contendo o nome do comando e seus
 * parâmetros quando necessário
 * @param redirect estrutura com contendo o tipo de redirecionador ou heredoc
 * e seu parametro ou arquivo a ser redirecionado
 * @note pode se usar uma array int para o file descriptor: int fd[2];
 */
typedef struct s_prompt
{
	char			*cmd;
	char			**args;
	t_redirect		*redirect;
	struct s_prompt	*next;
}					t_prompt;

/**
 * Estrutura que representa um prompt.
 * Contém informações relacionadas a um prompt incluindo:
 * *cmds -> Lista de comandos contendo um t_shell nó com todos os comandos
 * separados por pipes.
 * **envp -> Matriz atualizada contendo chaves e valores para o ambiente shell
 * pid -> ID do processo da instância do minishell
 */
typedef struct s_shell
{
	t_prompt	*cmds;
	char		**envp;
	pid_t		pid;
}			t_shell;

/**
 * PIPE & REDIRECT
 * @brief Por último, temos outra função de divisão chamada cmdsubsplit que
 * separa com <, |, ou >, mas apenas se esses caracteres estiverem fora das 
 * aspas:
 * output: {echo, "hello      there", how, are, 'you 'doing?, pixel, |, wc, -l, >, outfile, NULL}
*/

/* For sintax error */
// typedef struct	s_token
// {
// 	t_enum_tokens	token_id;
// 	char			*token;
// 	struct s_token	*prev;
// 	struct s_token	*next;
// }					t_token;

/* Lexer */
char	**strtrim_quotes(char **arr);
void	handle_quotes(char *s1, char *s2);
void	replace_spaces(char *s1);

/* Expander */
int		dollar(char **src, char **dst, int i);
int		outside_quotes(char **s2, char **s3, int i);
int		inside_dbquotes(char **s1, char **s2, int i, char *sig);
int		inside_spquotes(char **s1, char **s2, int i, char *sig);
char	*expander_inside(char *s1);
char	*expander_outside(char *s2);

/* Parser */
void	node_insert_redirects(t_redirect **root, int id, char *token);
void	fill_data_redirect(t_redirect *redirect, char **tokens);
int		cmds_len(char **tokens);

/* Utils */
void	print_arr(char **arr);
void	free_arr(char **arr);

/* Signals */
// void	ctrlc_sigint(int sig);

extern int	g_status;

#endif /* PARSER_H */