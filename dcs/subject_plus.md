# Minishell (Subject Comentado)

Program name | minishell
------------ | ---------
Turn in files| Makefile, *.h, *.c
Makefile     | NAME, all, clean, fclean, re
Arguments    | None
External functs.| readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
Libft authorized | Yes
Description  | Write a shell

### Funcoes externas:
<details>
  <summary>Click to expand </summary>
  
Funcoes externas | Header | Brief
------- | ------ | -----
**readline** | `<readline/readline.h>` | Fornece facilidades para leitura de linhas de texto de entrada.
**rl_clear_history** | `<readline/readline.h>` | Limpa o histórico de comandos no readline.
**rl_on_new_line** | `<readline/readline.h>` |  Informa ao readline que a próxima leitura deve começar em uma nova linha.
**rl_replace_line** | `<readline/readline.h>` | Substitui a linha de entrada atual no readline.
**rl_redisplay** | `<readline/readline.h>` | Redesenha a linha de entrada no readline.
**add_history** | `<readline/history.h>` | Adiciona uma linha ao histórico do readline.
**printf** | `<stdio.h>` | Imprime texto formatado no console.
**malloc** | `<stdlib.h>` | Aloca memória dinamicamente.
**free** | `<stdlib.h>` | Libera a memória alocada dinamicamente.
**write** | `<unistd.h>` | Escreve dados em um descritor de arquivo.
**access** | `<unistd.h>` | Verifica a existência e permissões de arquivos.
**open** | `<fcntl.h>` | Abre ou cria um arquivo.
**read** | `<unistd.h>` | Lê dados de um descritor de arquivo.
**close** | `<unistd.h>` | Fecha um descritor de arquivo.
**fork** | `<unistd.h>` | Cria um novo processo (fork).
**wait** | `<sys/wait.h>` | Aguardam o término de um processo filho.
**waitpid** | `<sys/wait.h>` | Aguardam o término de um processo filho.
**wait3** | `<sys/wait.h>` | Aguardam o término de um processo filho.
**wait4** | `<sys/wait.h>` | Aguardam o término de um processo filho.
**signal** | `<signal.h>` | Manipulam sinais.
**sigaction** | `<signal.h>` | Manipulam sinais.
**sigemptyset** | `<signal.h>` | Manipulam sinais.
**sigaddset** | `<signal.h>` | Manipulam sinais.
**kill** | `<signal.h>` | Envia um sinal para um processo.
**exit** | `<stdlib.h>` | Encerra o processo 
**getcwd** | `<unistd.h>` | Obtém o diretório de trabalho atual. 
**chdir** | `<unistd.h>` | Muda o diretório de trabalho. 
**stat** | `<sys/stat.h>` | Obtêm informações sobre arquivos.
**lstat** | `<sys/stat.h>` | Obtêm informações sobre arquivos.
**fstat** | `<sys/stat.h>` | Obtêm informações sobre arquivos.
**unlink** | `<unistd.h>` | Remove um arquivo.
**execve** | `<unistd.h>` | Executa um programa. 
**dup** | `<unistd.h>` | Duplicam descritores de arquivo.
**dup2** | `<unistd.h>` | Duplicam descritores de arquivo.
**pipe** | `<unistd.h>` | Cria um pipe.
**opendir** | `<dirent.h>` | Manipulam diretórios.
**readdir** | `<dirent.h>` | Manipulam diretórios.
**closedir** | `<dirent.h>` | Manipulam diretórios.
**strerror** | `<string.h>` | Convertem códigos de erro em mensagens de erro.
**perror** | `<string.h>` | Convertem códigos de erro em mensagens de erro.
**isatty** | `<unistd.h>` | Manipulam informações do terminal. 
**ttyname** | `<unistd.h>` | Manipulam informações do terminal. 
**ttyslot** | `<unistd.h>` | Manipulam informações do terminal. 
**ioctl** | `<ioctl.h>` | Controla dispositivos.
**getenv** | `<stdlib.h>` | Obtém o valor de uma variável de ambiente.
**tcsetattr** | `<termios.h>` | Configuram e obtêm atributos do terminal.
**tcgetattr** | `<termios.h>` | Configuram e obtêm atributos do terminal.
**tgetent** | `<term.h>` | Gerenciam terminais com capacidades ANSI.
**tgetflag** | `<term.h>` | Gerenciam terminais com capacidades ANSI.
**tgetnum** | `<term.h>` | Gerenciam terminais com capacidades ANSI.
**tgetstr** | `<term.h>` | Gerenciam terminais com capacidades ANSI.
**tgoto** | `<term.h>` | Gerenciam terminais com capacidades ANSI.
**tputs** | `<term.h>` | Gerenciam terminais com capacidades ANSI.
</details>

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
* **\>>** deve redirecionar a saída no modo de acréscimo.definir valor da variável 
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
#### Seu shell deve implementar os seguintes builtins:
1. `echo` com opção `-n`: *Exibe mensagens na tela.*
    - O comando `echo` no Bash é usado para imprimir argumantos ou variáveis de ambiente na tela, separados por um espaço, terminando com uma nova linha.
    - A opção `-n`  é usada para suprimir a adição de uma nova linha ao final da saída.
    ```Bash
    bash-3.2$ echo -n "Olá " && echo "Mundo"
    Olá Mundo
    ```
2. `cd` com apenas um caminho relativo ou absoluto: *Muda o diretório atual.*
    1. Caminho Absoluto: Um caminho absoluto é a localização exata do diretório ou arquivo no sistema de arquivos, começando pela raiz (root). Por exemplo, `/home/user/Documents` é um caminho absoluto.
    2. Caminho Relativo: Um caminho relativo é a localização de um diretório ou arquivo em relação ao diretório atual. Por exemplo, se você estiver no diretório `/home/user`, você pode mudar para o diretório Documents com `cd Documents`, que é um caminho relativo.
    - Mudar para o diretório home do usuário: `cd`
    - Mudar para um diretório relativo: `cd Documents`
    - Mudar para um diretório absoluto: `cd /home/user/Documents`
3. `pwd` sem opções: *Mostra o diretório atual.*
    - Imprime o nome do caminho absoluto do diretório de trabalho atual. 
4. `export` sem opções: *Define variáveis de ambiente.*
5. `unset` sem opções: *Remove variáveis de ambiente.*
6. `env` sem opções ou argumentos: *Mostra as variáveis de ambiente.*
7. `exit` sem opções: *Sai do shell.*
    - O comando `exit` no Bash é usado para terminar uma sessão de terminal. Ele fecha a shell atual. Se você estiver em uma sessão de terminal interativa, o terminal será fechado. Se o terminal estiver sendo executado como um processo filho (subshell), o processo filho será encerrado e o terminal pai permanecerá aberto.
---
  *A função **readline()** pode causar vazamentos de memória. Você não precisa consertá-los. Mas isso **não significa que seu próprio código, sim, o código que você escreveu, pode ter memmory leaks**.*

***Você deve se limitar à descrição do assunto. Tudo o que não é pedido não é obrigatório. Se você tiver alguma dúvida sobre algum requisito, tome o [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) como referência.***