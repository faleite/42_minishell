/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anda-cun <anda-cun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:28:51 by anda-cun          #+#    #+#             */
/*   Updated: 2023/10/11 19:05:43 by anda-cun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

extern int					g_signal;

/*STR,     str
	IN,      <
	OUT,     >
	APPEND,  >>
	HEREDOC, <<
	PIPE,    |
	END,     ; (end of command)*/

enum						e_tokens
{
	STR,
	IN,
	OUT,
	APPEND,
	HEREDOC,
	PIPE,
	END,
	EXEC,
};

typedef struct s_node
{
	char					*content;
	struct s_node			*next;
}							t_node;

typedef struct s_pair
{
	char					*key;
	char					*value;
	struct s_pair			*next;
}							t_pair;

typedef struct s_pipe
{
	int						fd[2];
	int						open;
	struct s_pipe			*next;
}							t_pipe;

typedef struct s_pid
{
	int						value;
	int						last;
	struct s_pid			*next;
}							t_pid;

typedef struct s_data
{
	char					*name;
	int						exit_status;
	int						exit;
	t_pid					*pid;
	t_pair					*env;
	t_pair					*exported_vars;
	char					**path;
	struct s_pipe			pipes;
	char					cwd[PATH_MAX];
}							t_data;

typedef struct s_arg
{
	char					*token;
	int						type;
}							t_arg;

typedef struct s_command_list
{
	char					*exec_path;
	t_arg					*arg;
	int						stdin;
	int						stdout;
	int						in_fd;
	int						out_fd;
	struct s_command_list	*next;
}							t_command_list;

/*BUILTINS*/
int							cd(t_data *data, char **str);
int							echo(t_data *data, char **str);
int							env(t_data *data, char **str);
int							export(t_data *data, char **str);
int							pwd(t_data *data, char **str);
int							unset(t_data *data, char **str);
int							exit_builtin(t_data *data, char **str);
int							is_builtin(t_data *data, char **args);
void						print_exported(t_node *node);
int							print_export_error(t_data *data, char *str);
size_t						len_to_char(char *str, char c);
int							check_dupes(t_pair *env, char *str);
int							add_to_list(char *str, t_pair *exported_vars);

/*PARSING*/
int							check_parse_errors(t_data *data, char *str, int i);
void						parsing(t_command_list *cmd_lst, char **splitter,
								int i, int j);
char						*treat_str(char *line, char aspas, int j);
int							ft_strleni(char **splitter, int i);
int							token(char *line);

/*EXECUTION*/

int							do_pipes(t_command_list *cmd_lst, t_pipe *pipes);
int							assign_fds(int in_fd, int out_fd);
void						add_pid(t_data *data, int pid,
								t_command_list *cmd_lst);
void						free_pid(t_data *data);
char						**get_env_list(t_pair *env, t_pair *exported_vars);
void						wait_for_execve(t_data *data, int *status);
void						wait_for_execve(t_data *data, int *status);
void						create_list(t_arg *arg, char **arg_list);

void						print_struct(t_command_list *lst);
int							z_cmp(char *str, char *cmp);
void						free_all(t_command_list *cmd_lst, char *changes,
								char **splitter);
int							create_executor(char *command);
void						sigint_handler(int signal);
int							expand_path(char *str);
t_pair						*get_env(char **envp);
void						free_nodes(t_node *node);
void						print_pairs(t_pair *pair);
void						free_pairs(t_pair *pair);
void						sort_list(t_pair **export);
int							print_syntax_error(t_data *data, char c);
int							print_file_error(char *s1, char *s2);
void						terminal_prompt(void);
int							mini_heredoc(t_data *data, char *str,
								t_command_list *cmd_lst);
int							check_cmd(t_data *data, t_command_list *cmd_lst,
								t_pipe *pipes);
char						*get_next_line(int fd);
char						**get_arg_list(t_arg *arg, int flag, int i,
								int len);
int							open_file(int *fd, char *filename, int flags,
								int perms);
void						revert_fds(t_command_list *cmd_lst);
int							check_path(t_data *data, t_command_list *cmd_lst,
								char **str, int i);
void						free_data(t_data *data);
void						free_args(t_arg *arg);
void						free_cmd(char **arg_list, t_command_list *cmd_lst);
void						init_cmd_lst(t_command_list *cmd_lst);
int							check_fds(t_data *data, t_command_list *cmd_lst,
								t_pipe *pipes, int i);
void						free_path(char **path);
int							replace_var(t_pair *env, char *str);
void						heredoc_sigint_handler(int signal);
void						expand_struct(t_data *data,
								t_command_list *cmd_lst);
int							is_valid(char *str);
char						*c_strdup(const char *s, char *freeit);
char						*c_strjoin(char *str, char *s);
int							parse(char **trying, int i, char *flag);
int							should_break(t_arg *arg, int i);
char						*ft_append(char *s, char c);

#endif
