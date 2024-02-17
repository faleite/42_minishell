/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:27 by faaraujo          #+#    #+#             */
/*   Updated: 2024/02/17 18:11:38 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* Lexer */
char		**ft_lexer(char *s1);
char		**lexer_sintax_error(char *s1);
char		*split_pipes(char *s1);
char		*split_redirects(char *s1);
void		strtrim_quotes(char **arr);
void		handle_pipe(char *s1, char *s2);
void		handle_redirects(char *s1, char *s2);
void		replace_spaces(char *s1);
void		end_quote(char *sig, char **s1, char **s2);
void		trim_spaces_end(char **tokens);

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
int			exit_cmd_null(t_command *command);
void		parser_tokens(t_token **lst, char **tokens);
void		init_struct(t_token **tail, t_token **head, char *token);
void		insert_token_end(t_token **head, char *token);
void		free_tokens(t_token **root);

/* Debugs */
void		print_arr(char **arr);
void		print_args(t_args *root);
void		print_redirects(t_redirect *root);
void		print_prompt(t_prompt *root);
void		print_tokens(t_token *root);

/* Signals */
void		handle_sigint(int sig);
void 		handle_sigint_clean(int sig);

#endif /* PARSER_H */
