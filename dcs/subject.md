# Minishell

Program name | minishell
------------ | ---------
Turn in files| Makefile, *.h, *.c
Makefile     | NAME, all, clean, fclean, re
Arguments    | None
External functs.| readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
Libft authorized | Yes
Description  | Write a shell

## Seu shell deve:
* Exibir um **prompt** ao aguardar um novo comando.
* Ter um **histórico** de trabalho.
* Pesquise e inicie o executável correto (com base na variável **PATH** ou usando um
caminho relativo ou absoluto).
* Evite usar mais de **uma variável global** para indicar um sinal recebido. Considere as implicações: esta abordagem garante que o seu manipulador de sinal não acessará suas principais estruturas de dados.

***Tome cuidado. Esta variável global não pode fornecer nenhuma outra informação ou acesso a dados além do número de um sinal recebido. Portanto, é proibido o uso de estruturas do tipo "norm" no escopo global.***

* Não interpretar aspas não fechadas ou caracteres especiais que não sejam exigidos pelo assunto, como **\\** (barra invertida) ou **;** (ponto e vírgula).
* Lidar **'** (aspas simples) que deve evitar que o shell interprete os metacaracteres na sequência citada.
* Lidar **"** (aspas duplas) que deve evitar que o shell interprete os metacaracteres na sequência citada, exceto **$** (cifrão).
* **Implementar redirecionamentos:**
  * **<** deve redirecionar a entrada.
  * **\>** deve redirecionar a saída.
  * **<<** deve receber um delimitador e, em seguida, leia a entrada até que uma linha contendo o delimitador seja vista. No entanto, não é necessário atualizar o histórico!
  * **\>>** deve redirecionar a saída no modo de acréscimo.
* Implementar **pipes** (**|** caractere). A saída de cada comando no pipeline é conectada à entrada do próximo comando por meio de um pipe.
* Lidar com **variáveis de ambiente** (**$** seguidas por uma sequência de caracteres) que devem se expandir para seus valores.
* Lidar com **$?** que deve se expandir para o status de saída do pipeline em primeiro plano executado mais recentemente.
* Lidar com **ctrl-C**, **ctrl-D** e **ctrl-\\** que devem se comportar como no **bash**.
  * No modo interativo:
    * **ctrl-C** exibe um novo prompt em uma nova linha.
    * **ctrl-D** sai do shell.
    * **ctrl-\\** não faz nada.
* Seu shell deve implementar os seguintes **builtins** (componentes internos):
  * **echo** com opção -n
  * **cd** com apenas um caminho relativo ou absoluto
  * **pwd** sem opções
  * **export** sem opções
  * **unset** sem opções
  * **env** sem opções ou argumentos
  * **exit** sem opções

  *A função **readline()** pode causar vazamentos de memória. Você não precisa consertá-los. Mas isso **não significa que seu próprio código, sim, o código que você escreveu, pode ter memmory leaks**.*

***Você deve se limitar à descrição do assunto. Tudo o que não é pedido não é obrigatório. Se você tiver alguma dúvida sobre algum requisito, tome o [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) como referência.***