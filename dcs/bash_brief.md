# Resumo manual do Bash
>*Bourne-Again SHell*

### Forma interativa e não interativa
O **Shell** pode ser usado de forma interativa ou não interativa. No modo\
interativo, eles aceitam entradas digitadas do teclado. Ao executar de forma\
não interativa, os shells executam comandos lidos de um arquivo.

### Execução de comandos **síncrona** e **assíncrona**
Um shell permite a execução de comandos GNU, tanto de forma síncrona quanto\
assíncrona. O shell aguarda a conclusão dos comandos síncronos antes de aceitar\
mais entradas; os comandos assíncronos continuam a ser executados em paralelo\
com o shell enquanto ele lê e executa comandos adicionais. As construções de\
redirecionamento permitem um controle refinado da entrada e saída desses comandos.\
Além disso, o shell permite o controle sobre o conteúdo dos ambientes dos comandos.

### Comandos integrados (builtins)
Os shells também fornecem um pequeno conjunto de comandos integrados (builtins)\
que implementam funcionalidades impossíveis ou inconvenientes de serem obtidas\
por meio de utilitários separados. Por exemplo, **cd**, **break**, **continue**\
e **exec** não podem ser implementados fora do shell porque manipulam diretamente\
o próprio shell. Os componentes internos **history**, **getopts**, **kill** ou\
**pwd**, entre outros, podem ser implementados em utilitários separados, mas são\
mais convenientes para usar como comandos internos. Todos os componentes internos\
do shell são descritos nas seções subsequentes.

Alguns comandos builtins no Bash incluem:

1. `echo`: Exibe mensagens na tela.
2. `cd`: Muda o diretório atual.
3. `pwd`: Mostra o diretório atual.
4. `export`: Define variáveis de ambiente.
5. `unset`: Remove variáveis de ambiente.
6. `env`: Mostra as variáveis de ambiente.
7. `exit`: Sai do shell.
8. `alias`: Cria um alias para um comando.
9. `source` (ou `.`): Executa comandos a partir de um arquivo.
10. `history`: Exibe histórico de comandos.
11. `set`: Configura opções do shell.

Esses são alguns dos comandos builtins mais comuns. Há outros também, dependendo\
da versão do Bash e das configurações específicas do sistema.

## Comandos builtins utilizados no projeto
1. `echo` with option -n
2. `cd` with only a relative or absolute path
3. `pwd` with no options
4. `export` with no options
5. `unset` with no options
6. `env` with no options or arguments
7. `exit` with no options

*A opção `-n` no comando `echo` no Bash é usada para suprimir a adição de uma nova linha ao final da saída. Quando você usa `echo -n`, a próxima linha de saída ou texto será impressa na mesma linha, sem quebra de linha automática no final. Isso pode ser útil em scripts ou em situações em que você deseja controlar explicitamente a formatação da saída.*
```Bash
bash-3.2$ echo -n "Olá " && echo "Mundo"
Olá Mundo
```

### control operator
Os operadores de controle (control operators) no Bash são usados para controlar o fluxo de execução dos comandos. Aqui estão alguns operadores de controle comuns:

1. `;` (ponto e vírgula): Permite a execução sequencial de comandos, um após o outro.

   ```bash
   comando1 ; comando2
   ```

2. `&&` (AND lógico): Executa o segundo comando apenas se o primeiro for bem-sucedido (retorna status de saída 0).

   ```bash
   comando1 && comando2
   ```

3. `||` (OR lógico): Executa o segundo comando apenas se o primeiro falhar (retorna status de saída diferente de 0).

   ```bash
   comando1 || comando2
   ```

4. `&` (ampersand): Permite que um comando seja executado em segundo plano.

   ```bash
   comando &
   ```

5. `|` (pipe): Redireciona a saída de um comando como entrada para outro comando.

   ```bash
   comando1 | comando2
   ```

6. `;;` (ponto e vírgula duplo): Usado em instruções `case` dentro de um bloco `select` ou `case` para indicar o final de um padrão e o final do bloco `case`.

   ```bash
   case $variavel in
       padrão1) comandos1 ;;
       padrão2) comandos2 ;;
       *) padrão_geral ;;
   esac
   ```

7. `;&` (ampersand duplo): Usado em instruções `case` para indicar que, após a execução dos comandos sob um padrão, a execução deve continuar no próximo padrão.

   ```bash
   case $variavel in
       padrão1) comandos1 ;&
       padrão2) comandos2 ;;
   esac
   ```

8. `;;&` (ampersand duplo e ponto e vírgula duplo): Similar ao `;&`, mas inicia a execução no próximo padrão sem verificar as condições.

   ```bash
   case $variavel in
       padrão1) comandos1 ;;
       padrão2) comandos2 ;;&
       padrão3) comandos3 ;;
   esac
   ```

9. `|&` (pipe e ampersand): Redireciona tanto a saída padrão quanto a saída de erro do comando anterior para o próximo comando.

   ```bash
   comando1 |& comando2
   ```
Esses são alguns dos operadores de controle mais comuns no Bash. Eles são utilizados para compor e controlar o fluxo de execução de comandos no shell.

### Token
Um token é uma sequência de caracteres que o shell trata como uma unidade. Existem cinco tipos de tokens: palavras, operadores, caracteres de controle de fluxo, caracteres de expansão e caracteres de separação.

### Word
Uma palavra é uma sequência de caracteres que o shell trata como um nome de comando, nome de variável, nome de arquivo ou algum outro tipo de unidade. Existem três tipos de palavras: palavras reservadas, palavras literais e palavras de operador. As palavras não podem incluir metacaracteres sem aspas.

### Operação do Shell
1. Lê uma linha de entrada. (No caso de um arquivo de script, o shell lê uma linha do arquivo.)
2. Divide a entrada em palavras e operadores, obedecendo às regras de expansão e aos caracteres de escape.
3. Analisa os tokens em comandos simples e compostos.
4. Executa as diversas expansões de shell, dividindo os tokens expandidos em listas de nomes de arquivos e comandos e argumentos.
5. Executa quaisquer redirecionamentos necessários e remove os operadores de redirecionamento e seus operandos da lista de argumentos.
6. Executa um comando.
7. Opcionalmente, aguarda a conclusão do comando e coleta seu status de saída.

### Citação
A citação é usada para remover o significado especial de certos caracteres ou palavras-chave para o shell. Existem três tipos de citação: 'aspas simples', "aspas duplas" e barra invertida \\.

### Comandos Shell
Um comando shell simples como `echo a b c` consiste no próprio comando seguido de argumentos, separados por espaços.\
Comandos shell mais complexos são compostos de comandos simples organizados juntos de diversas maneiras: em um pipeline no qual a saída de um comando se torna a entrada de um segundo, em um loop ou construção condicional ou em algum outro agrupamento.

### Expansões do Shell


>Leitura Manual bash em...: 3.1.2.5 Quoting