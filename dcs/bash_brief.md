# Resumo manual do Bash
>*Bourne-Again SHell*

## Forma interativa e não interativa
O **Shell** pode ser usado de forma interativa ou não interativa. No modo\
interativo, eles aceitam entradas digitadas do teclado. Ao executar de forma\
não interativa, os shells executam comandos lidos de um arquivo.

## Execução de comandos **síncrona** e **assíncrona**
Um shell permite a execução de comandos GNU, tanto de forma síncrona quanto\
assíncrona. O shell aguarda a conclusão dos comandos síncronos antes de aceitar\
mais entradas; os comandos assíncronos continuam a ser executados em paralelo\
com o shell enquanto ele lê e executa comandos adicionais. As construções de\
redirecionamento permitem um controle refinado da entrada e saída desses comandos.\
Além disso, o shell permite o controle sobre o conteúdo dos ambientes dos comandos.

## Comandos integrados (builtins)
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

## control operator
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

## Token
Um token é uma sequência de caracteres que o shell trata como uma unidade. Existem cinco tipos de tokens: palavras, operadores, caracteres de controle de fluxo, caracteres de expansão e caracteres de separação.

## Word
Uma palavra é uma sequência de caracteres que o shell trata como um nome de comando, nome de variável, nome de arquivo ou algum outro tipo de unidade. Existem três tipos de palavras: palavras reservadas, palavras literais e palavras de operador. As palavras não podem incluir metacaracteres sem aspas.

## Operação do Shell
1. Lê uma linha de entrada. (No caso de um arquivo de script, o shell lê uma linha do arquivo.)
2. Divide a entrada em palavras e operadores, obedecendo às regras de expansão e aos caracteres de escape.
3. Analisa os tokens em comandos simples e compostos.
4. Executa as diversas expansões de shell, dividindo os tokens expandidos em listas de nomes de arquivos e comandos e argumentos.
5. Executa quaisquer redirecionamentos necessários e remove os operadores de redirecionamento e seus operandos da lista de argumentos.
6. Executa um comando.
7. Opcionalmente, aguarda a conclusão do comando e coleta seu status de saída.

## Citação
A citação é usada para remover o significado especial de certos caracteres ou palavras-chave para o shell. Existem três tipos de citação: 'aspas simples', "aspas duplas" e barra invertida \\.

## Comandos Shell
Um comando shell simples como `echo a b c` consiste no próprio comando seguido de argumentos, separados por espaços.\
Comandos shell mais complexos são compostos de comandos simples organizados juntos de diversas maneiras: em um pipeline no qual a saída de um comando se torna a entrada de um segundo, em um loop ou construção condicional ou em algum outro agrupamento.

## Redirecionamento
O redirecionamento é uma forma de alterar a entrada e/ou saída padrão de um comando. O redirecionamento é aplicado a um comando após a expansão de variáveis, mas antes da execução do comando. O redirecionamento é indicado por um operador de redirecionamento seguido por um nome de arquivo.\
Os redirecionamentos são processados ​​na ordem em que aparecem, da esquerda para a direita.
### Redirecionamento de entrada: `comando [n]< arquivo`
O redirecionamento de entrada faz com que o arquivo seja aberto para leitura no descritor de arquivo `n`, ou na entrada padrão (descritor de arquivo 0) caso nnão seja especificado.
### Redirecionando Saída: `comando > arquivo`
O operador de redirecionamento de saída > no Bash é usado para redirecionar a saída de um comando para um arquivo. Ele permite que você armazene o resultado da execução de um comando em um arquivo, sobrescrevendo o conteúdo existente ou criando um novo arquivo, dependendo da situação.
`echo 'Olá, Mundo!' > saudacao.txt`
*echo 'Olá, Mundo!' é redirecionada para o arquivo saudacao.txt.*

No caso da string com aspas duplas ao incluir o ponto de exclamação ! no final da string "Olá, Mundo!", o Bash interpreta isso como uma tentativa de buscar e executar um comando no histórico que começa com a string "Olá, Mundo!". Como o Bash não encontra tal comando no histórico, ele exibe o prompt dquote>, indicando que está esperando que você forneça o restante do comando.

Para evitar esse comportamento, você pode escapar o caractere de ponto de exclamação usando uma barra invertida \:
`echo "Olá, Mundo\!" > saudacao.txt`

### Redirecionamento de saída `>>` 
No Bash é utilizado para redirecionar a saída de um comando para um arquivo, mas, ao contrário de `>`, ele não substitui o conteúdo existente do arquivo. Em vez disso, `>>` anexa a saída ao final do arquivo, preservando o conteúdo anterior.

A sintaxe básica é a seguinte:

```bash
comando >> arquivo
```

Isso significa que a saída do comando será adicionada ao final do arquivo especificado. Se o arquivo não existir, ele será criado.

Exemplo:

```bash
echo "Primeira linha" > arquivo.txt
echo "Segunda linha" >> arquivo.txt
```

Após esses comandos, o arquivo `arquivo.txt` terá o seguinte conteúdo:

```
Primeira linha
Segunda linha
```

O primeiro `echo` usa `>` para criar e escrever a "Primeira linha" no arquivo, enquanto o segundo `echo` usa `>>` para anexar a "Segunda linha" ao final do arquivo existente.

Essa é uma maneira útil de acumular dados em um arquivo sem perder o conteúdo anterior.

### Here Documents `<<`
Aqui estão alguns exemplos adicionais de here documents (`<<`) com diferentes comandos no Bash:

1. `cat` com Here Document
```bash
cat << EOL
Linha 1
Linha 2
Linha 3
EOL
```
Este exemplo utiliza um here document para fornecer entrada para o comando `cat`.

2. `grep` com Here Document
```bash
grep "padrão" << EOL
Linha com padrão
Outra linha sem padrão
EOL
```
Neste caso, um here document é usado para fornecer linhas para o comando `grep`, que busca por um padrão específico.

3. `sed` com Here Document
```bash
sed 's/antes/depois/' << EOL
Texto com "antes".
EOL
```
Este exemplo utiliza um here document para fornecer texto ao comando `sed`, que substitui "antes" por "depois".

5. `ssh` com Here Document
```bash
ssh usuario@host << EOL
comando_remoto_1
comando_remoto_2
EOL
```
Neste exemplo, um here document é usado para enviar comandos remotamente via SSH.

5. `ftp` com Here Document
```bash
ftp -n << EOL
open exemplo.com
user usuário senha
put arquivo.txt
bye
EOL
```
Aqui, um here document é utilizado para enviar comandos FTP.

Os here documents são versáteis e podem ser usados com vários comandos diferentes, permitindo a entrada de dados de forma eficiente em scripts ou na linha de comando.

## Expansão de Comando Simples
A expansão de comando simples é a forma mais básica de expansão de shell. Ela ocorre quando um comando é precedido por um caractere de crase ` ou entre parênteses $(). O shell executa o comando dentro da expansão de comando simples e substitui a expansão pelo resultado da execução. Nenhuma etapa de tokenização é realizada, portanto, o resultado da expansão de comando simples é uma única palavra.\
Exemplo:
```bash
resultado=`ls`
echo "Os arquivos no diretório são: $resultado"
```

###  Busca e Execução de Comandos

Depois que um comando for dividido em palavras, se resultar em um comando simples e uma lista opcional de argumentos, as seguintes ações serão executadas.

1. Se o nome do comando não contiver barras, o shell tentará localizá-lo. Se existir uma função shell com esse nome, essa função será invocada conforme descrito em [Funções Shell](https://www.gnu.org/software/bash/manual/bash.html#Shell-Functions).
Se o nome não corresponder a uma função, o shell procurará por ele na lista de componentes internos do shell. Se uma correspondência for encontrada, esse recurso interno será invocado.
2. Se o nome não for uma função shell nem embutido e não contiver barras, o Bash procurará em cada elemento `$PATH` um diretório contendo um arquivo executável com esse nome. Bash usa uma tabela hash para lembrar os nomes completos dos arquivos executáveis ​​para evitar `PATH` pesquisas múltiplas (veja a descrição hashem Bourne Shell Builtins ). Uma pesquisa completa dos diretórios `$PATH` será executada somente se o comando não for encontrado na tabela hash. Se a pesquisa não for bem-sucedida, o shell procurará uma função de shell definida chamada `command_not_found_handle`. Se essa função existir, ela será invocada em um ambiente de execução separado com o comando original e os argumentos do comando original como seus argumentos, e o status de saída da função se tornará o status de saída desse subshell. Se essa função não estiver definida, o shell imprimirá uma mensagem de erro e retornará um status de saída 127.
4. Se a pesquisa for bem-sucedida ou se o nome do comando contiver uma ou mais barras, o shell executará o programa nomeado em um ambiente de execução separado. O argumento 0 é definido com o nome fornecido e os argumentos restantes do comando são definidos com os argumentos fornecidos, se houver.
5. Se esta execução falhar porque o arquivo não está em formato executável e o arquivo não é um diretório, ele é assumido como um script de shell e o shell o executa conforme descrito em [Shell Scripts](https://www.gnu.org/software/bash/manual/bash.html#Shell-Scripts).
6. Se o comando não foi iniciado de forma assíncrona, o shell aguarda a conclusão do comando e coleta seu status de saída.

## Meio Ambiente (Environment / env)
Quando um programa é invocado, ele recebe uma matriz de strings chamada ambiente . Esta é uma lista de pares nome-valor, no formato name=value.

Bash oferece várias maneiras de manipular o ambiente. Na invocação, o shell verifica seu próprio ambiente e cria um parâmetro para cada nome encontrado, marcando-o automaticamente para exportprocessos filhos. Os comandos executados herdam o ambiente. O `export` e o `declare -x` comandos permitem que parâmetros e funções sejam adicionados e excluídos do ambiente. Se o valor de um parâmetro do ambiente for modificado, o novo valor passa a fazer parte do ambiente, substituindo o antigo. O ambiente herdado por qualquer comando executado consiste no ambiente inicial do shell, cujos valores podem ser modificados no shell, menos quaisquer pares removidos pelos e `unset` e o `export -n` comandos, além de quaisquer adições por meio dos comandos `export` e `declarar -x`.

O ambiente para qualquer comando ou função simples pode ser aumentado temporariamente prefixando-o com atribuições de parâmetros, conforme descrito em Parâmetros do Shell. Estas instruções de atribuição afetam apenas o ambiente visto por esse comando.

Se o `-k` é definida (consulte The Set Builtin ), então todas as atribuições de parâmetros são colocadas no ambiente para um comando, não apenas aquelas que precedem o nome do comando.

Quando o Bash invoca um comando externo, a variável `$_` é definido como o caminho completo do comando e passado para esse comando em seu ambiente.

##  [Status de Saída](https://www-gnu-org.translate.goog/software/bash/manual/bash.html?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt-BR&_x_tr_pto=wapp#Exit-Status)

## [Signals](https://www-gnu-org.translate.goog/software/bash/manual/bash.html?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt-BR&_x_tr_pto=wapp#Signals)

## Comandos builtins do Bash

### Comando `cd` (change directory)
É usado para mudar o diretório atual no terminal. Quando usado sem nenhuma opção de flag ou argumento, ele muda para o diretório home do usuário atual.

Existem dois tipos de caminhos que você pode usar com `cd`: relativo e absoluto.

1. Caminho Absoluto: Um caminho absoluto é a localização exata do diretório ou arquivo no sistema de arquivos, começando pela raiz (root). Por exemplo, `/home/user/Documents` é um caminho absoluto.

2. Caminho Relativo: Um caminho relativo é a localização de um diretório ou arquivo em relação ao diretório atual. Por exemplo, se você estiver no diretório `/home/user`, você pode mudar para o diretório Documents com `cd Documents`, que é um caminho relativo.

Aqui estão alguns exemplos de como usar `cd`:

- Mudar para o diretório home do usuário: `cd`
- Mudar para um diretório relativo: `cd Documents`
- Mudar para um diretório absoluto: `cd /home/user/Documents`
- Mudar para o diretório pai: `cd ..`
- Mudar para o diretório anterior: `cd -`

### Comando `exit`
O comando `exit` no Bash é usado para terminar uma sessão de terminal. Ele fecha a shell atual. Se você estiver em uma sessão de terminal interativa, o terminal será fechado. Se você estiver em um script de shell, a execução do script será encerrada.

Você também pode fornecer um código de status opcional com `exit` para indicar se o script terminou com sucesso ou se houve algum erro. Por exemplo, `exit 0` indica um término bem-sucedido, enquanto `exit 1` geralmente indica que ocorreu algum erro.

### Comando `export`
A função `export` no Bash é usada para definir variáveis de ambiente. As variáveis de ambiente são um tipo especial de variável que está disponível para processos filhos de um processo. 

Quando você usa `export` sem flags, você está definindo uma variável de ambiente que será passada para todos os processos filhos do shell atual. 

Por exemplo, se você quiser definir uma variável de ambiente chamada `TEST` e dar a ela o valor `Hello World`, você usaria o seguinte comando:

```bash
export TEST="Hello World"
```

Depois de definir uma variável de ambiente, você pode acessá-la em qualquer lugar do seu script usando `$TEST`. 

Se você quiser ver todas as variáveis de ambiente atualmente definidas, você pode usar o comando `env` sem opções ou argumentos.

### Special Builtins
Por razões históricas, o padrão POSIX classificou vários comandos internos como especiais . Quando o Bash está sendo executado no modo POSIX , os comandos internos especiais diferem de outros comandos internos em três aspectos:

1. Recursos internos especiais são encontrados antes das funções do shell durante a pesquisa de comandos.
2. Se um built-in especial retornar um status de erro, um shell não interativo será encerrado.
3. As instruções de atribuição que precedem o comando permanecem em vigor no ambiente shell após a conclusão do comando.

Quando o Bash não está sendo executado no modo POSIX , esses componentes internos não se comportam de maneira diferente do restante dos comandos internos do Bash. O modo Bash POSIX é descrito em Modo Bash POSIX .

Estes são os recursos especiais do POSIX :
`break : . continue eval exec exit export readonly return set shift trap unset`

>Leitura Manual bash em.: [4 Comandos internos do Shell - echo](https://www-gnu-org.translate.goog/software/bash/manual/bash.html?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt-BR&_x_tr_pto=wapp#index-echo)\
[Manual](https://www.gnu.org/software/bash/manual/bash.html#Shell-Builtin-Commands)