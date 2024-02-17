/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:27 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/17 18:00:10 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

// Creating path
char		*cmd_path(char *cmd);

// Frees
void		free_map(char **map);

t_command	*init_exec(t_prompt *prompt);
char		*var_path(void);

// Enviroment variables management
void		ft_fillenvp(char *envp[]);
void		ft_envp(char *envp[]);
t_envp		*getev(void);
t_envparr	*getevarr(void);

int			ft_open_all(t_command *current);

int			exit_final(void);
int			exit_finald(void);
int			clean_newline(void);
void		print_envp(t_envp *head);
void		print_commands(t_command *head);
void		free_struct(t_command *head);
char		*add_name(char *str);
char		*add_value(char *str);
t_data		*data(void);
t_envp		*insert_end_envp(t_envp **head);

void		free_path(char *str);
void		free_envp(t_envp *head);
void		free_struct(t_command *head);
void		free_prompt2(t_prompt *head);

// Executing
void		executing(t_command *head);
t_command	*find_tail(t_command *head);

// Builtins
int			exit_builtin(t_command *command);
int			is_builtin(char	*arg);
int			is_just_quotes(char *map);
void		echo(t_command *command, int outfile, int infile);
void		pwd(int outfile);
void		cd(t_command *command, int outfile);
void		unset(t_command *command);
void		env(int outfile);
void		ft_export(char **key_value, int outfile);
void		builtins(t_command *command, int infile, int outfile);

// Envp utils
void		update_value(char *name, char *value);
char		*get_value(char *name);
void		fill_envp(t_envp **getev, char **envp);
void		update_shlvl(void);
char		**update_env(char **old);
char		**envp_exec(char *envp[]);
void		new_envp(char **envp);

int			commands_wait(t_command *head);

void	command_error(t_command *command);
int	to_execute(t_command *head);

// Builtin utils
int			is_long(char *str);
int			in_str(char *str, char c);


int	change_in(t_command *command, int infile);
int	change_out(t_command *command, int outfile);
void	ft_dup2(int infile, int outfile);

int	ft_open_infile_heredoc(t_command *current, char *delimiter);

#endif /* EXECUTOR_H */
