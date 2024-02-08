# code behind the scenes

# heredoc
```c
int	handle_heredoc(char **tokens)
{
	int		i;
	int		quotes;
	char	*heredoc;
	char	*eof;
	char	*out;
	
	i = 0;
	eof = ft_strdup("");
	out = ft_strdup("");
	while(tokens && tokens[i])
	{
		heredoc = "";
		if (!ft_strcmp(tokens[i], HERE_DOC) && tokens[++i])
		{
			while (heredoc)
			{
				quotes = trim_quotes(tokens[i], &eof);
				heredoc = readline("> ");
				if (!heredoc)
				{
					msg_error_hd(tokens[i]);
					write_heredoc(&tokens[i], &eof, &out, &quotes);
					i++;
				}
				else if (!ft_strcmp(heredoc, eof))
				{
					write_heredoc(&tokens[i], &eof, &out, &quotes);
					i++;
					break ;
				}
				else
				 	fill_documents(heredoc, &out);
			}
		}
		else
			i++;
	}
	free(out);
	free(eof);
	return (0);
}
```

# structs
```c
void	free_stack(t_stack **root)
{
	t_stack	*curr;
	t_stack	*aux;

	curr = *root;
	while (curr)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}
```

```c
void	insert_end(t_stack **root, int value)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(1);
	new_node->next = NULL;
	new_node->nbr = value;
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

```c
int	struct_len(t_stack *root)
{
	int		s_len;
	t_stack	*curr;

	s_len = 0;
	curr = root;
	while (curr != NULL)
	{
		s_len++;
		curr = curr->next;
	}
	return (s_len);
}
```

```c
static void	aux_inside(int *i, char *sig, char **s1, char **s2)
{
	if (**s1 == '\"')
		*sig = 1;
	(*s2)[(*i)++] = *(*s1)++;
}
```

```c
void	*expander_inside(char *s1, char *s2)
{
	int		i;
	char	sig;

	i = 0;
	sig = 1;
	while (*s1)
	{
		if (sig == 1)
		{
			if (*s1 == '\"')
				sig = *s1;
			s2[i++] = *s1++;
		}
		else
			i = inside_dbquotes(&s1, &s2, i, &sig);
	}
	s2[i] = '\0';
}

char	*expander_inside(char *s1)
{
	int		i;
	char	sig;
	char	*s2;

	i = 0;
	sig = 1;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 2));
	if (!s2)
		return (NULL);
	while (*s1)
	{
		if (sig == 1)
		{
			if (*s1 == '\"')
				sig = *s1;
			s2[i++] = *s1++;
		}
		else
			i = inside_dbquotes(&s1, &s2, i, &sig);
	}
	s2[i] = '\0';
	return (s2);
}
```

```c
int	main(void)
{
	char	s1[] = "echo \"$HOME '$PWD' >>>\" $USER '$PWD' ~///fal";
				// output: /home/fal '/home/fal' >>> fal $PWD /home/fal///fal
	char	**arr;
	// char	*s2;*

	arr = sep_replace(s1);
	//s2 = sep_replace(s1);
	//s2 = expand_var(s1);*
	//printf("%s\n", s2);*
	//free(s2);*
	printf("String Original: %s\n", s1);
	printf("\nFirst parser:\n");
	print_arr(arr);
	free_arr(arr);
	//cmdline();
	// printf("env: %s\n", getenv("USER"));
	// printf("env: %s\n", getenv("HOME"));
	return (0);
}
```

## CODES
```c
// Primeira solução para o problema de separar os tokens
void	handle_quotes(char *s1, char *s2)
{
	char	sig;

	sig = 1;
	while (*s1)
	{
		if (sig == 1)
		{
			while (*s1 == ' ')
			{
				*s2++ = '\2';
				s1++;
			}
			if (*s1 == '\"' || *s1 == '\'')
				sig = *s1;
			*s2++ = *s1++;
		}
		if (sig == '\"' || sig == '\'')
		{
			if (*s1 == sig)
				sig = 1;
			*s2++ = *s1++;
		}
	}
	*s2 = '\0';
}
```

```c
// Segunda solução para o problema de separar os redicts e pipes
void	red_pipe(char **s2, char **s1)
{
	if (is_redpipe(*(*s1 - 1)) && !is_redpipe(**s1))
		*(*s2)++ = '\2';
	if (!is_redpipe(*(*s1 - 1)) && is_redpipe(**s1))
		*(*s2)++ = '\2';
}
```
