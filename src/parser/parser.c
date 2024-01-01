/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:03:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/01/01 21:02:33 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_shell	*cmd(void)
{
	static t_shell	s;

	s.infile = -1;
	s.outfile = -1;
	return (&s);
}

t_shell	*add_nodes(char **tokens)
{
	t_shell	*curr;
	t_shell	*cmds;
	int		i;

	i = 0;
	curr = cmd();
	cmds = curr;
	while (tokens[i])
	{
		if (!ft_strncmp(tokens[i], "|", 1))
		{
			curr->next = cmd();
			curr = curr->next;
		}
		i++;
	}
	return (cmds);
}

int	handle_input_redirection(t_shell *curr, char *token)
{
	if (!token && access(token, R_OK) == -1)
	{
		ft_putstr_fd("Erro: Sem permissao de leitura para o arquivo\n", 2);
		return (-1);
	}
	curr->infile = open(token, O_RDONLY);
	if (curr->infile < 0)
	{
		ft_putstr_fd("Erro: Nao foi possivel abrir o arquivo\n", 2);
		return (-1);
	}
	return (0);
}

int	handle_output_redirection(t_shell *curr, char *token)
{
	int	flag;

	flag = O_WRONLY | O_CREAT;
	if (!token && access(token, W_OK) == -1)
	{
		ft_putstr_fd("Erro: sem permissao de escrita para o arquivo\n", 2);
		return (-1);
	}
	if (token[1] == '>')
		flag |= O_APPEND;
	else
		flag |= O_TRUNC;
	curr->outfile = open(token, flag, 0644);
	if (curr->outfile < 0)
	{
		ft_putstr_fd("Erro: impossivel abrir o arquivo para escrita\n", 2);
		return (-1);
	}
	return (0);
}

t_shell	*handle_redirection(t_shell *cmds, char **tokens)
{
	t_shell	*curr;
	int		i;

	i = 0;
	curr = cmds;
	while (curr)
	{
		while (tokens[i] && ft_strncmp(tokens[i], "|", 1))
		{
			if (!ft_strncmp(tokens[i], "<", 1))
			{
				if (handle_input_redirection(curr, tokens[++i]) < 0)
					return (NULL);
			}
			else if (!ft_strncmp(tokens[i], ">", 1))
			{
				if (handle_output_redirection(curr, tokens[++i]) < 0)
					return (NULL);
			}
			i++;
		}
		i++;
		curr = curr->next;
	}
	return (cmds);
}

int	token_count(char **arr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (arr[i++])
		len++;
	return (len);
}

//$ <<Makefile cat| echo "$PWD <$?> | 'hola'" "$HOME"/src | echo $? '$?' |'tr' -d / >outfile

t_shell	*put_cmds(t_shell *cmds, char **tokens)
{
	t_shell	*curr;
	int		i;
	int		j;

	i = 0;
	curr = cmds;
	while (curr)
	{
		curr->full_cmd = malloc(sizeof(char *) * (token_count(tokens) + 1));
		j = 0;
		while (tokens[i] && ft_strncmp(tokens[i], "|", 1))
		{
			if (!ft_strncmp(tokens[i], "<", 1) || \
				!ft_strncmp(tokens[i], ">", 1) || \
				!ft_strncmp(tokens[i], ">>", 2))
				i += 2;
			else
			{
				curr->full_cmd[j++] = ft_strdup(tokens[i]);
				if (!curr->full_path)
					curr->full_path = ft_strdup(tokens[i]);
			}
		}
		curr->full_cmd[j] = NULL;
		i++;
		curr = curr->next;
	}
	return (cmds);
}
