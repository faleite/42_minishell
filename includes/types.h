/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:36:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/14 19:19:56 by feden-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "minishell.h"

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
	int					is_last;
	int					is_exec;
	struct s_command	*next;
}						t_command;

typedef struct s_envp
{
	char			*name;
	char			*value;
	struct s_envp	*next;
}					t_envp;

typedef struct s_envparray
{
	char	**envp;
}			t_envparr;

/* DATAS */
typedef struct s_data
{
	char		*path;
	int			exit_status;
	int			h_flag;
	int			h_fd;
	t_envp		*envp;
	t_command	*exec;
}				t_data;

#endif // TYPES_H
