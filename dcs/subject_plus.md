# Minishell (Subject Comentado)

Program name | minishell
------------ | ---------
Turn in files| Makefile, *.h, *.c
Makefile     | NAME, all, clean, fclean, re
Arguments    | None
External functs.| readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
Libft authorized | Yes
Description  | Write a shell

## Seu shell deve:
### Modo interativo
* Exibir um **prompt** ao aguardar um novo comando.
  * Na forma interativa o **Shell** aceita entradas digitadas do teclado.
---
* Ter um **histórico** de trabalho.
* Pesquise e inicie o executável correto (com base na variável **PATH** ou usando um
caminho relativo ou absoluto).
* Evite usar mais de **uma variável global** para indicar um sinal recebido. Considere as implicações: esta abordagem garante que o seu manipulador de sinal não acessará suas principais estruturas de dados.

***Tome cuidado. Esta variável global não pode fornecer nenhuma outra informação ou acesso a dados além do número de um sinal recebido. Portanto, é proibido o uso de estruturas do tipo "norm" no escopo global.***

* Não interpretar aspas não fechadas ou caracteres especiais que não sejam exigidos pelo assunto, como **\\** (barra invertida) ou **;** (ponto e vírgula).
* Lidar **'** (aspas simples) que deve evitar que o shell interprete os metacaracteres na sequência citada.
* Lidar **"** (aspas duplas) que deve evitar que o shell interprete os metacaracteres na sequência citada, exceto **$** (cifrão).

### **Implementar redirecionamentos:**
* **<** deve redirecionar a entrada. 
  * O redirecionamento de entrada faz com que o arquivo cujo nome resulta da expansão do `word` seja aberto para leitura no descritor de arquivo `n`, ou na entrada padrão (descritor de arquivo 0) caso nnão seja especificado. Ex. `[n]< word`
* **\>** deve redirecionar a saída. refere-se à saída padrão (descritor de arquivo 1)
  * O operador de redirecionamento de saída > no Bash é usado para redirecionar a saída de um comando para um arquivo. Ele permite que você armazene o resultado da execução de um comando em um arquivo, sobrescrevendo o conteúdo existente ou criando um novo arquivo, dependendo da situação.\
`echo 'Olá, Mundo!' > saudacao.txt`\
*echo 'Olá, Mundo!' é redirecionada para o arquivo saudacao.txt*
* **<<** deve receber um delimitador e, em seguida, leia a entrada até que uma linha contendo o delimitador seja vista. No entanto, não é necessário atualizar o histórico!
  * Os here documents (<<) no shell Bash são usados para fornecer entrada para um comando a partir de um bloco de texto diretamente no script ou na linha de comando. Eles são especialmente úteis quando você deseja passar várias linhas de entrada para um comando sem ter que criar um arquivo temporário.\
A sintaxe básica é a seguinte:
```bash
comando << DELIMITADOR
Texto da entrada
Mais linhas de entrada
DELIMITADOR
```
* **\>>** deve redirecionar a saída no modo de acréscimo.
  * O operador de redirecionamento de saída >> no Bash é utilizado para redirecionar a saída de um comando para um arquivo, mas, ao contrário de >, ele não substitui o conteúdo existente do arquivo. Em vez disso, >> anexa a saída ao final do arquivo, preservando o conteúdo anterior.
* Implementar **pipes** (**|** caractere). A saída de cada comando no pipeline é conectada à entrada do próximo comando por meio de um pipe.
* Lidar com **variáveis de ambiente** (**$** seguidas por uma sequência de caracteres) que devem se expandir para seus valores.

### Lidar com **$?** (esta é uma das variáveis de Controle de Fluxo)
Deve se expandir para o status de saída do pipeline em primeiro plano executado mais recentemente.
* A variável especial **$?** no Bash contém o código de retorno (exit status) do último comando executado. O código de retorno é um numero inteiro que indica se o comando foi executado com sucesso ou se ocorreu algum erro durante a execução.
  * Se **$?** for igual a 0, isso significa que o último comando foi executado com sucesso.
  * Se **$?** for diferente de 0, indica que ocorreu algum erro durante a execução do último comando.

* Lidar com **ctrl-C**, **ctrl-D** e **ctrl-\\** que devem se comportar como no **bash**.
  * No modo interativo:
    * **ctrl-C** exibe um novo prompt em uma nova linha.
    * **ctrl-D** sai do shell.
    * **ctrl-\\** não faz nada.

### Comandos integrados/simples (builtins)
* Seu shell deve implementar os seguintes **builtins**:
  1. `echo` com opção `-n`: *Exibe mensagens na tela.*
  2. `cd` com apenas um caminho relativo ou absoluto: *Muda o diretório atual.*
  3. `pwd` sem opções: *Mostra o diretório atual.*
  4. `export` sem opções: *Define variáveis de ambiente.*
  5. `unset` sem opções: *Remove variáveis de ambiente.*
  6. `env` sem opções ou argumentos: *Mostra as variáveis de ambiente.*
  7. `exit` sem opções: *Sai do shell.*

*A opção `-n` no comando `echo` no Bash é usada para suprimir a adição de uma nova linha ao final da saída. Quando você usa `echo -n`, a próxima linha de saída ou texto será impressa na mesma linha, sem quebra de linha automática no final. Isso pode ser útil em scripts ou em situações em que você deseja controlar explicitamente a formatação da saída.*
```Bash
bash-3.2$ echo -n "Olá " && echo "Mundo"
Olá Mundo
```
---
  *A função **readline()** pode causar vazamentos de memória. Você não precisa consertá-los. Mas isso **não significa que seu próprio código, sim, o código que você escreveu, pode ter memmory leaks**.*

***Você deve se limitar à descrição do assunto. Tudo o que não é pedido não é obrigatório. Se você tiver alguma dúvida sobre algum requisito, tome o [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) como referência.***