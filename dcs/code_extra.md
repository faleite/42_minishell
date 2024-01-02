# code behind the scenes

# structs
```c
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
```

# Test for here_doc
```bash
faaraujo@c2r3s3:~/00/shell$ cat << ""
> ola
> 
ola
faaraujo@c2r3s3:~/00/shell$ cat << ""
> 
faaraujo@c2r3s3:~/00/shell$ cat << "ola"    

> "ola"
> ola


"ola"
```

# Test fo $1, $@, $*, $#, $0
```bash
faaraujo@c2r3s3:~/00/shell$ $#
0: command not found
faaraujo@c2r3s3:~/00/shell$ $?
127: command not found
faaraujo@c2r3s3:~/00/shell$ $1
faaraujo@c2r3s3:~/00/shell$ $@
faaraujo@c2r3s3:~/00/shell$ ls $1
dcs  includes  libft  LICENSE  Makefile  minishell  README.md  src  supp.supp
faaraujo@c2r3s3:~/00/shell$ ls $@
dcs  includes  libft  LICENSE  Makefile  minishell  README.md  src  supp.supp
```

```bash
<<Makefile cat| echo "$PWD <$?> | 'hola'" "$HOME"/src | echo $? '$?' |'tr' -d / >outfile
'"$SHELL"'"$SHELL"
$HOME' '$USER' >>>" '$PWD' $SHELL #Caso de quebra
echo "hello  '  there" how are 'you 'doing? $USER |wc -l >outfile
echo "$PWD < > \\ | 'hola'" ~/src ${USER} $HOME |'tr' -d / >outfile
echo|cat || teste >>>> >>ts >>>tdb ||t
echo "$HOME '$PWD' >>>" $USER '$PWD' ~///fal
<<$USER "$PWD '$USER'u | $'USER' 'hola'" ~/src '$USER' $HOME|'tr' -d / >outfile
$USER '$USER'  4 $ $'USER' $  "SHELL" "$SHELL"   $    $
<<Makefile cat| echo \"$PWD < > | 'hola'\" $USER || 'tr' -d / >outfile
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

