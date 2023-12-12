# code behind the scenes
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

