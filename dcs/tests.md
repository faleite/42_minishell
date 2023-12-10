# Testes da linha de comando

```bash
 <Makefile cat| echo "$PWD 'hola'" ~/src | 'tr' -d / >outfile
```
*Aqui está a explicação de cada token na linha de comando:*

- `< Makefile`: Este é um redirecionamento de entrada. O shell lê o arquivo `Makefile` como entrada para o próximo comando.

- `cat`: Este é o comando `cat`, que lê arquivos e os imprime na saída padrão.

- `|`: Este é o operador pipe. Ele pega a saída do comando à sua esquerda e a usa como entrada para o comando à sua direita.

- `echo "$PWD 'hola'"`: Este é o comando `echo`, que imprime seus argumentos na saída padrão. `$PWD` é uma variável de ambiente que contém o diretório de trabalho atual. `'hola'` é apenas uma string.

- `~/src`: Este é um caminho para o diretório `src` na pasta inicial do usuário atual.

- `'tr' -d /`: Este é o comando `tr`, que traduz ou deleta caracteres. Neste caso, ele está sendo usado para deletar todas as ocorrências do caractere `/`.

- `>outfile`: Este é um redirecionamento de saída. Ele direciona a saída do comando à sua esquerda para o arquivo `outfile`.

Por favor, note que a linha de comando que você forneceu parece ter alguns erros. Por exemplo, o comando `cat` não tem argumentos, então ele vai tentar ler da entrada padrão, mas a entrada padrão já está sendo lida pelo redirecionamento de entrada `< Makefile`. Além disso, `~/src` parece estar fora de lugar, pois não está claro para qual comando ele deveria ser um argumento.

```bash
# Teste de comandos simples
string: echo "hello      there" how are 'you 'doing? $USER |wc -l >outfile
output: {echo, "hello      there", how, are, 'you 'doing?, $USER, |wc, -l, >outfile, NULL}

# Teste de variáveis de ambiente
$ echo $PATH
$ echo $USER

# Teste de comandos compostos
echo export cd \'$USER\' $ my name is grep>><<><>0  Makefile  \"|\'$USER grep\' $USER$USER $$\"| \'grep x@ $PATH\' >| file $USE | $USER$user$1eugen$USER$1USER--$-
```