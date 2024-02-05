/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:27 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/05 03:42:04 by feden-pe         ###   ########.fr       */
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
# include <linux/limits.h>
# include <signal.h> /* */
# include <sys/ioctl.h> /* */
# include <fcntl.h> /* open */
# include <stdbool.h>
# include <sys/wait.h>


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

/* For sintax error */
typedef struct s_token
{
	char			*token;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_redirect
{
	t_enum_token		*tokens_id;
	char				**tokens;
	struct s_redirect	*next;
}					t_redirect;

typedef struct s_args
{
	char			*path;
	char			**args;
	struct s_args	*next;
}					t_args;

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
typedef struct s_command
{
	char				*path;
	char				**args;
	int					fd[2];
	int					infile_fd;
	int					outfile_fd;
	pid_t				pid;
	t_prompt			*prompt;
	struct s_command	*next;
}			t_command;

typedef struct s_envp
{
	char		*name;
	char		*value;
	struct s_envp	*next;
}		t_envp;

typedef struct	s_envparray
{
	char	**envp;
}		t_envparr;

typedef struct	s_data
{
	char	*path;
	int		g_status;
	t_envp	*envp;
}			t_data;


/* Lexer */
char		**ft_lexer(char *s1);
char		*split_pipes(char *s1);
char		*split_redirects(char *s1);
void		strtrim_quotes(char **arr);
void		handle_pipe(char *s1, char *s2);
void		handle_redirects(char *s1, char *s2);
void		replace_spaces(char *s1);
void		end_quote(char *sig, char **s1, char **s2);

/* Expander */
int			dollar(char **src, char **dst, int i);
int			outside_quotes(char **s2, char **s3, int i);
int			inside_dbquotes(char **s1, char **s2, int i, char *sig);
int			inside_spquotes(char **s1, char **s2, int i, char *sig);
char		*exit_value(char *s1);
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
int			is_redirect(char *token);
void		free_arr(char **arr);

/* Errors */
int			sintax_errors(char *line);
int			handle_pipe_err(t_token *lst);
int			handle_newline_err(t_token *lst);
int			handle_big_redir(t_token *lst);
int			handle_quotes_err(t_token *lst);
int			msg_error(t_token *lst, char *type_err, int exit_status);
void		parser_tokens(t_token **lst, char **tokens);
void		init_struct(t_token **tail, t_token **head, char *token);
void		insert_token_end(t_token **head, char *token);
void		free_tokens(t_token **root);

/* Heredoc */
int			open_heredoc(void);
int			trim_quotes(char *token, char **eof);
int			handle_heredoc(char **tokens);
char		*expander_hd(char *s2);
void		process_heredoc(char **token, char **eof, char **out, int *i);
void		write_heredoc(char **token, char **eof, char **out, int *quotes);
void		msg_error_hd(char *type_err);
void		fill_documents(char *doc, char **bkp);

/* Debugs */
void		print_arr(char **arr);
void		print_args(t_args *root);
void		print_redirects(t_redirect *root);
void		print_prompt(t_prompt *root);
void		print_tokens(t_token *root);


// Creating path
char	*cmd_path(char *cmd);

// Frees
void	free_map(char **map);

t_command	*init_exec(t_prompt *prompt);
void	var_path(t_envp *getev);

// Enviroment variables management
void	ft_fillenvp(char *envp[]);
t_envparr	*getevarr(void);
void	ft_envp(char *envp[]);
t_envp	*getev(void);

int		ft_open_all(t_command *current);

void	print_envp(void);
void	print_commands(t_command *head);
void	free_struct(t_command *head);
int		exit_final(t_command *command);
t_data *data(void);
t_envp	*insert_end_envp(void);
char	*add_name(char *str);
char	*add_value(char *str);

// Executing
void	executing(t_command *head);
// Builtins
void	echo(t_command *command, int outfile);
void	pwd(void);
void	cd(t_command *command);
void	unset(t_command *command);
int		exit_builtin(t_command *command);
void	env(void);
void	ft_export(char **key_value);
int		is_builtin(char	*arg);
void	builtins(t_command *command, int infile, int outfile);

// Envp utils
void	update_value(char *name, char *value);
char	*get_value(char *name);
void	fill_envp(t_envp **getev, char **envp);

// Builtin utils
int			is_long(char *str);

#endif /* PARSER_H */
