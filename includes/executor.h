/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:27 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/18 20:00:06 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

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
# define INFILE "<"
# define OUTFILE ">"
# define APPEND ">>"
# define HERE_DOC "<<"

typedef enum e_token
{
	NO_REDIR,
	INFILE_ID,
	OUTFILE_ID,
	APPEND_ID,
	HEREDOC_ID,
	PIPE_ID,
	ARGS_ID,
}		t_enum_token;

typedef struct s_redirect
{
	t_enum_token		*tokens_id;
	char				**tokens;
	struct s_redirect	*next;
}					t_redirect;

typedef struct	s_args
{
	char			*cmd;
	char			**args;
	struct s_args	*next;
}					t_args;

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
	char			*path;
	char			**args;
	t_enum_token	*tokens_id;
	char			**tokens;
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
	char		*infile;
	char		*outfile;
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
char		**ft_lexer(char *s1);
char		**strtrim_quotes(char **arr);
void		handle_quotes(char *s1, char *s2);
void		replace_spaces(char *s1);

/* Expander */
int			dollar(char **src, char **dst, int i);
int			outside_quotes(char **s2, char **s3, int i);
int			inside_dbquotes(char **s1, char **s2, int i, char *sig);
int			inside_spquotes(char **s1, char **s2, int i, char *sig);
char		*expander_inside(char *s1);
char		*expander_outside(char *s2);

/* Parser */
void		parser_prompt(t_prompt **prompt, t_args *arg, \
						t_redirect *red, char **toks);
void		fill_prompt(t_prompt *node, t_args *arg, \
						t_redirect *red, char **toks);
void		free_prompt(t_prompt **root);
t_prompt	*insert_end_parser(t_prompt **root);

/* Utils redirects parser */
void		free_redirects(t_redirect **root);
void		fill_redirects(t_redirect *node, char **tokens, int *i);
void		parser_redirects(t_redirect **redirect, char **tokens);
t_redirect	*insert_end_redirects(t_redirect **root);

/* Utils args parser */
void		free_args(t_args **root);
void		parser_args(t_args **args, char **tokens);
void		fill_args(t_args *node, char **tokens, int *i);
t_args		*insert_end_args(t_args **root);

/* Utils */
int			ft_strcmp(char *s1, char *s2);
int			count_tokens(char **tokens);
void		free_arr(char **arr);

/* Errors */
int				sintax_errors(char **tokens);
void			msg_error(char *msg, int exit_status);

/* Debugs */
void		print_arr(char **arr);
void		print_args(t_args *root);
void		print_redirects(t_redirect *root);
void		print_prompt(t_prompt *root);

// Creating path
char	*cmd_path(char *envp[], char *cmd);

/* Signals */
// void	ctrlc_sigint(int sig);

extern int	g_status;

# endif /* EXECUTOR_H */
