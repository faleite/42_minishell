```c
// <<Makefile cat| echo "$PWD <$?> | 'hola'" "$HOME"/src | echo $? '$?' |'tr' -d / >outfile

t_shell	*cmd(void)
{
	static t_shell	s;

	s.infile = -1;
	s.outfile = -1;
	return (&s);
}

int	handle_input_redirection(t_shell *curr, char *token)
{
	if (!token || access(token, R_OK) == -1)
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
	if (!token || access(token, W_OK) == -1)
	{
		ft_putstr_fd("Erro: sem permissao de escrita para o arquivo\n", 2);
		return (-1);
	}
	if (ft_strlen(token) > 1 && token[1] == '>')
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

static int	token_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

t_shell	*put_cmds(char **tokens)
{
	t_shell	*curr;
	t_shell *cmds;
	int		i;
	int		j;

	i = 0;
	cmds = curr;
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
				// if (!curr->full_path)
				// 	curr->full_path = ft_strdup(tokens[i]);
			}
		}
		//curr->full_cmd[j] = NULL;
		i++;
		curr = curr->next;
	}
	return (cmds);
}


int	num_of_cmds(char **tokens)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (tokens[i])
	{
		if (ft_strncmp(tokens[i], "|", 1) == 0)
			len++;
		i++;
	}
	return (++len);
}


t_shell	*add_nodes(char **tokens)
{
	t_shell	*curr;
	t_shell	*cmds;
	int		len;

	len = cmds_len(tokens);
	curr = (t_shell *)malloc(sizeof(t_shell));
	if (!curr)
		return (NULL);
	curr->infile  = -1;
	curr->outfile  = -1;
	cmds = curr;
	while (--len)
	{
		curr->next = (t_shell *)malloc(sizeof(t_shell));
		if (!curr->next)
			return (NULL);
		curr = curr->next;
		curr->infile  = -1;
		curr->outfile  = -1;
	}
	curr->next = NULL;
	return (cmds);
}

void	insert_end(t_shell **root, char **tokens, char *token)
{
	t_shell	*new_node;
	t_shell	*curr;

	new_node = malloc(sizeof(t_shell));
	if (!new_node)
		exit(1);
	new_node->next = NULL;
	new_node->full_cmd;
	new_node->full_path;
	new_node->infile;
	new_node->outfile;
	if (!*root)
	{
		*root = new_node;
		return ;
	}
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}
```