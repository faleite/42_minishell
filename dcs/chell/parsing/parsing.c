/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eportela <eportela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:26:24 by eportela          #+#    #+#             */
/*   Updated: 2023/09/21 15:26:24 by eportela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	treat_str_handler(char *newline, char **line, char aspas, int *j)
{
	if (!aspas && token(line[0]) != 0)
	{
		newline[(*j)++] = 2;
		newline[(*j)++] = *line[0]++;
		if (token(line[0]) != 0)
			newline[(*j)++] = *line[0]++;
		newline[(*j)++] = 2;
		return (1);
	}
	return (0);
}

char	*treat_str(char *line, char aspas, int j)
{
	char	*newline;

	newline = malloc(ft_strlen(line) * 5 + 1);
	while (*line != '\0')
	{
		if (!aspas && (*line == '"' || *line == '\''))
		{
			aspas = *line++;
			newline[j++] = aspas;
		}
		else if (treat_str_handler(newline, &line, aspas, &j))
			continue ;
		else if (!aspas && *line == ' ' && *line++)
			newline[j++] = 2;
		else if (aspas && aspas == *line)
		{
			newline[j++] = *line++;
			aspas = 0;
		}
		else
			newline[j++] = *line++;
	}
	newline[j] = '\0';
	return (newline);
}

void	solve_rest(t_command_list *cmd_lst, char **splitter, int i)
{
	t_command_list	*cmd_newlst;

	if (splitter[i] && z_cmp(splitter[i], "|"))
	{
		cmd_newlst = malloc(sizeof(t_command_list));
		cmd_newlst->arg = malloc(sizeof(t_arg) * \
			(ft_strleni(splitter, ++i) + 1));
		cmd_lst->next = cmd_newlst;
		parsing(cmd_newlst, splitter, i, 0);
	}
	else if (splitter[i] && z_cmp(splitter[i], ";"))
	{
		cmd_lst->next = NULL;
		return ;
	}
	else
		cmd_lst->next = NULL;
}

void	parsing(t_command_list *cmd_lst, char **splitter, int i, int j)
{
	while (splitter[i] && !z_cmp(splitter[i], "|") && !z_cmp(splitter[i], ";"))
	{
		if (!ft_strncmp("./", splitter[i], 2) || !ft_strncmp("/", \
			splitter[i], 1))
		{
			cmd_lst->arg[j].token = ft_strdup(splitter[i]);
			cmd_lst->arg[j].type = EXEC;
		}
		else if (token(splitter[i]) != STR && splitter[i + 1])
		{
			cmd_lst->arg[j].type = token(splitter[i]);
			cmd_lst->arg[j].token = ft_strdup(splitter[i + 1]);
			i++;
		}
		else
		{
			cmd_lst->arg[j].type = token(splitter[i]);
			cmd_lst->arg[j].token = ft_strdup(splitter[i]);
		}
		j++;
		i++;
	}
	cmd_lst->arg[j].token = NULL;
	cmd_lst->arg[j].type = 0;
	solve_rest(cmd_lst, splitter, i);
}
