/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:27 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/05 03:16:01 by feden-pe         ###   ########.fr       */
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
# include <stdbool.h>
# include <sys/wait.h>

// typedef enum e_token
// {
// 	NO_REDIR,
// 	INFILE_ID,
// 	OUTFILE_ID,
// 	APPEND_ID,
// 	HEREDOC_ID,
// 	PIPE_ID,
// 	ARGS_ID,
// }		t_enum_token;

// typedef struct s_prompt
// {
// 	char			*path;
// 	char			**args;
// 	t_enum_token	*tokens_id;
// 	char			**tokens;
// 	struct s_prompt	*next;
// }					t_prompt;

/**
 * Estrutura que representa um prompt.
 * Contém informações relacionadas a um prompt incluindo:
 * *cmds -> Lista de comandos contendo um t_shell nó com todos os comandos
 * separados por pipes.
 * **envp -> Matriz atualizada contendo chaves e valores para o ambiente shell
 * pid -> ID do processo da instância do minishell
 */
// typedef struct s_command
// {
// 	char				*path;
// 	char				**args;
// 	int					fd[2];
// 	int					infile_fd;
// 	int					outfile_fd;
// 	pid_t				pid;
// 	// char				*infile;
// 	// char				*outfile;
// 	t_prompt			*prompt;
// 	struct s_command	*prev;
// 	struct s_command	*next;
// }			t_command;

// typedef struct s_envp
// {
// 	char		*name;
// 	char		*value;
// 	struct s_envp	*next;
// }		t_envp;

// typedef struct	s_envparray
// {
// 	char	**envp;
// }		t_envparr;


// // Creating path
// char	*cmd_path(char *cmd);

// // Frees
// void	free_map(char **map);

// t_command	*init_exec(t_prompt *prompt);

// // Enviroment variables management
// void	ft_fillenvp(char *envp[]);
// t_envparr	*getevarr(void);
// void	ft_envp(char *envp[]);
// t_envp	*getev(void);

// int		ft_open_all(t_command *current);


// void	print_commands(t_command *head);

extern int	g_status;

# endif /* EXECUTOR_H */
