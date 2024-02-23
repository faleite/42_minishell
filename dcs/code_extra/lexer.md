# Lexer

```c
/**
 * Substitui separador
 * echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
 * echo/2"hello      there"/2how/2are/2'you 'doing?/2$USER/2|wc/2-l/2>outfile
*/
char	**ft_lexer(char *s1)
{
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;
	char	**arr;

	arr = NULL;
	s2 = split_pipes(s1);
	s3 = split_redirects(s2);
	free(s2);
	replace_spaces(s3);
	s4 = expander_outside(s3);
	free(s3);
	s5 = expander_inside(s4);
	free(s4);
	arr = ft_split(s5, '\2');
	free(s5);
	return (arr);
}

char	*split_redirects(char *s1)
{
	char	*s2;

	s2 = ft_calloc((ft_strlen(s1) * 2 + 1), sizeof(char));
	handle_redirects(s1, s2);
	replace_spaces(s2);
	return (s2);
}

char	*split_pipes(char *s1)
{
	char	*s2;

	s2 = ft_calloc((ft_strlen(s1) * 2 + 1), sizeof(char));
	handle_pipe(s1, s2);
	replace_spaces(s2);
	return (s2);
}
```

# Expander

```c
char	*expander_inside(char *s1)
{
	int		i;
	char	sig;
	char	*s2;

	i = 0;
	sig = 1;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 1000 + 1));
	if (!s2)
		return (NULL);
	while (*s1)
	{
		if (sig == 1)
		{
			if (*s1 == '\"' || *s1 == '\'')
				sig = *s1;
			s2[i++] = *s1++;
		}
		else if (sig == '\'')
			i = inside_spquotes(&s1, &s2, i, &sig);
		else
			i = inside_dbquotes(&s1, &s2, i, &sig);
	}
	s2[i] = '\0';
	return (s2);
}

char	*expander_outside(char *s2)
{
	int		i;
	char	sig;
	char	*s3;

	i = 0;
	sig = 1;
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s2) * 1000 + 1));
	while (*s2)
	{
		if (sig == 1)
		{
			if (*s2 == '\"' || *s2 == '\'')
				sig = *s2;
			i = outside_quotes(&s2, &s3, i);
		}
		else
		{
			if (*s2 == sig)
				sig = 1;
			s3[i++] = *s2++;
		}
	}
	s3[i] = '\0';
	return (s3);
}

int	inside_spquotes(char **s1, char **s2, int i, char *sig)
{
	if (**s1 == '\'')
		*sig = 1;
	(*s2)[i++] = *(*s1)++;
	return (i);
}
```

# DOLLAR

```c
char	*exit_value(char *s1)
{
	int		i;
	int		j;
	char	*s2;
	char	*s3;

	i = 0;
	j = 0;
	s2 = ft_itoa(data()->exit_status);
	s3 = (char *)(malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!s3)
		return (NULL);
	while (s2[j])
		s3[i++] = s2[j++];
	while (*s1++)
		s3[i++] = *s1;
	s3[i] = '\0';
	free(s2);
	return (s3);
}

static int	print_dollar(char c)
{
	return (c == '/' || c == '.' || c == ',' || c == '%' || \
			c == ':' || c == '=' || c == ';' || c == ')' || \
			c == '+' || c == ']' || c == '}' || c == '!' || \
			c == '~' || c == '^' || c == '|');
}

int	dollar(char **src, char **dst, int i)
{
	char	*start;
	char	*end;
	char	*var;
	char	*value;

	start = ++(*src);
	while (**src != ' ' && **src != '\2' && **src != '\'' && \
			**src != '\"' && **src != '$' && !print_dollar(**src) && **src)
		(*src)++;
	end = *src;
	var = (char *)malloc(sizeof(char) * ((end - start) + 1));
	ft_strlcpy(var, start, ((end - start) + 1));
	if (var[0] == '?')
		value = exit_value(var);
	else
		value = get_value(var);
	if (value)
	{
		ft_strlcpy(*dst + i, value, (ft_strlen(*src) + ft_strlen(value) + 1));
		i += ft_strlen(value);
	}
	if (var[0] == '?')
		free(value);
	free(var);
	return (i);
}

int	inside_dbquotes(char **s1, char **s2, int i, char *sig)
{
	if (**s1 == '$' && *(*s1 + 1) != '\'' && !print_dollar(*(*s1 + 1)))
		i = dollar(s1, s2, i);
	else
	{
		if (**s1 == '\"')
			*sig = 1;
		(*s2)[i++] = *(*s1)++;
	}
	return (i);
}

int	outside_quotes(char **s2, char **s3, int i)
{
	if ((**s2 && **s2 == '$') && !print_dollar(*(*s2 + 1)))
	{
		if (*(*s2 + 1) == '\"')
			(*s3)[i++] = *(*s2)++;
		else if (*(*s2 + 1) == '\'')
			(*s2)++;
		else if (*(*s2 + 1) == '\2' || *(*s2 + 1) == '\0')
			(*s3)[i++] = *(*s2)++;
		else if (*(*s2 + 1) != '\2' && *(*s2 + 1) != '\0')
			i = dollar(s2, s3, i);
	}
	else if (**s2)
		(*s3)[i++] = *(*s2)++;
	return (i);
}
```
