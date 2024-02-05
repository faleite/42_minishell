# Funções uteis para o minishell

*Aqui estão algumas possíveis utilizações dessas funções em um minishell:*

- **readline**: Usada para ler uma linha de entrada do usuário. Esta função é útil para obter comandos do usuário.

- **rl_clear_history**: Usada para limpar o histórico de comandos. Pode ser útil se você quiser implementar um comando para limpar o histórico.

- **rl_on_new_line**: Informa ao readline que a próxima leitura deve começar em uma nova linha. Isso pode ser útil para formatar a saída do shell.

- **rl_replace_line**: Substitui a linha de entrada atual. Isso pode ser útil para implementar recursos como a edição de linha.

- **rl_redisplay**: Redesenha a linha de entrada. Isso pode ser útil para atualizar a linha de entrada após uma alteração.

- **add_history**: Adiciona uma linha ao histórico. Isso é útil para implementar um histórico de comandos.

- **printf**: Usada para imprimir mensagens para o usuário.

- **malloc** e **free**: Usadas para alocar e liberar memória dinamicamente. Essas funções são fundamentais em muitos aspectos da programação em C.

- **write**: Usada para escrever dados em um descritor de arquivo. Isso pode ser útil para redirecionar a saída de um comando.

- **access**: Verifica a existência e permissões de arquivos. Isso pode ser útil para verificar se um comando ou arquivo existe antes de tentar executá-lo.

- **open**, **read**, **close**: Usadas para manipular arquivos. Essas funções são úteis para implementar redirecionamento de entrada/saída e tubulação (piping).

- **fork**, **wait**, **waitpid**, **wait3**, **wait4**: Usadas para criar e gerenciar processos. Essas funções são fundamentais para a execução de comandos em um shell.

- **signal**, **sigaction**, **sigemptyset**, **sigaddset**, **kill**: Usadas para manipular sinais. Isso é útil para implementar o tratamento de sinais, como interrupções de teclado (Ctrl+C).

- **exit**: Usada para encerrar o processo do shell.

- **getcwd**, **chdir**: Usadas para obter e alterar o diretório de trabalho atual. Isso é útil para implementar comandos como `cd`.

- **stat**, **lstat**, **fstat**: Usadas para obter informações sobre arquivos. Isso pode ser útil para implementar comandos como `ls`.

- **unlink**: Usada para remover arquivos. Isso é útil para implementar o comando `rm`.

- **execve**: Usada para executar programas. Isso é fundamental para um shell, que precisa executar comandos.

- **dup**, **dup2**, **pipe**: Usadas para duplicar descritores de arquivo e criar pipes. Isso é útil para implementar redirecionamento de entrada/saída e tubulação (piping).

- **opendir**, **readdir**, **closedir**: Usadas para manipular diretórios. Isso é útil para implementar comandos como `ls`.

- **strerror**, **perror**: Usadas para converter códigos de erro em mensagens de erro. Isso é útil para fornecer feedback útil ao usuário quando ocorrem erros.

- **isatty**, **ttyname**, **ttyslot**, **ioctl**: Usadas para manipular informações do terminal. Isso pode ser útil para implementar recursos como a coloração de saída.

- **getenv**: Usada para obter o valor de uma variável de ambiente. Isso é útil para implementar comandos como `echo $HOME`.

- **tcsetattr**, **tcgetattr**: Usadas para configurar e obter atributos do terminal. Isso pode ser útil para implementar recursos como o modo raw.

- **tgetent**, **tgetflag**, **tgetnum**, **tgetstr**, **tgoto**, **tputs**: Usadas para gerenciar terminais com capacidades ANSI. Isso pode ser útil para implementar recursos como a coloração de saída.