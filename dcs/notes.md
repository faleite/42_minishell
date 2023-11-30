# NOTES

## Writing Your Own Shell

**A  implementação  do  shell  é  dividida  em  três  partes:**
1. **Parser**
  - O Parser é o componente de software que lê a linha de comando como “ls al” e a coloca em uma estrutura de dados chamada **Command Table** que irá armazenar os comandos que serão executados.
2. **Executor**
  - O executor pegará a tabela de comandos gerada pelo **parser** e para cada **SimpleCommand** no array criará um novo processo. Também criará, se necessário, pipes para comunicar a saída de um processo à entrada do próximo. Além disso, ele redirecionará a entrada padrão, a saída padrão e o erro padrão se houver algum redirecionamento.
3. **Shell Subsystems**
*Outros subsistemas que completam seu shell são:*
  - Variáveis de ambiente: Expressões no formato ${VAR} são expandidas com a variável de ambiente correspondente. Além disso, o shell deve ser capaz de definir, expandir e imprimir vars de ambiente.
  - Wildcards: Argumentos no formato a*a são expandidos para todos os arquivos que correspondem a eles no diretório local e em vários diretórios.
  - Subshells: Argumentos entre `` (crases) são executados e a saída é enviada como entrada para o shell.

>leitura cap pag. 4

## Word Keys
- **Lexical analysis**: O processo de dividir um fluxo de texto em palavras, frases, símbolos ou outros elementos significativos chamados tokens.
- **Tokens**: Um token é uma sequência de caracteres que pode ser tratada como uma unidade em um programa de computador. Por exemplo, um programa de computador pode tratar as palavras em uma instrução de comando como tokens.
- **Syntax analysis/Parsing**: O processo de analisar uma sequência de símbolos, seja em texto, tokens ou árvores de sintaxe, que se conformam com as regras de uma gramática formal.
- **abstract syntax tree (AST)**: Uma árvore de sintaxe abstrata (AST) ou árvore de análise sintática é uma representação em árvore de uma estrutura sintática derivada de uma sequência de entrada (geralmente tokens). Uma árvore de sintaxe abstrata é "abstrata" no sentido de que ela não representa explicitamente nenhum aspecto do layout da árvore de análise sintática original derivada da entrada. Em vez disso, ela expressa a estrutura da árvore de análise sintática original de maneira concisa e fácil de manipular.

[<img align="center" src="./ast.png" width="60%"/>](./ast.png)
```c
// An abstract syntax tree for the following code for the Euclidean algorithm:

while b ≠ 0:
    if a > b:
        a := a - b
    else:
        b := b - a
return a
```
- [**The Recursive Descent**](https://en.wikipedia.org/wiki/Recursive_descent_parser): O analisador de descida recursiva é um tipo de analisador preditivo recursivo para linguagens de programação. Esses analisadores funcionam com uma função para cada símbolo não terminal (ou seja, cada tipo de frase) da gramática. Essas funções geralmente são chamadas de rotinas de análise sintática ou procedimentos de análise sintática. Cada uma dessas funções analisa ou reconhece uma frase particular da linguagem. A função para um símbolo não terminal geralmente invoca as funções para os símbolos não terminais que podem começar essas frases. Isso reflete a estrutura hierárquica da gramática. Essas funções recursivamente invocam outras funções até que os símbolos terminais sejam encontrados. A recursão termina quando as funções atingem os símbolos terminais da gramática. Essas funções de análise sintática geralmente retornam algum tipo de valor para a função que as chamou, indicando que a frase foi reconhecida com sucesso ou não. Se a frase foi reconhecida, então a função de análise sintática pode retornar algum tipo de valor para a função que a chamou, indicando que a frase foi reconhecida com sucesso. Se a frase foi reconhecida, então a função de análise sintática pode retornar algum tipo de valor para a função que a chamou, indicando que a frase foi reconhecida com sucesso. Se a frase não foi reconhecida, então a função de análise sintática geralmente gera algum tipo de mensagem de erro para o usuário, indicando que a frase não foi reconhecida e, portanto, não faz parte da linguagem.
[*Teoria da computação*](https://en.wikipedia.org/wiki/Theory_of_computation)
- [**CFG (Context Free Grammar)**](https://en.wikipedia.org/wiki/Context-free_grammar): 
>*Nota: nem todas as gramáticas funcionam com a Descendência Recursiva, a gramática escolhida não deve ter ambiguidade ou recursão à esquerda .*