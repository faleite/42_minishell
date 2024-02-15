# Testes da linha de comando

# Exit status
```bash
shell$ cat
^C
shell$ $?
130: command not found
shell$

[minishell]$ $?
Error: 32512 command not found!

[minishell]$ echo oi
oi[minishell]$ 
```


# Principal
```bash
cat<<EOF test>>append|echo "$PWD <$?> | 'hola'" "$HOME"/src |<infile echo $? '$?'|'tr' -d />outfile
cat <<EOF test >>append| echo "$PWD <$?> | 'hola'" "$HOME"/src | <infile echo $? '$?' |'tr' -d / >outfile
<file cat | cat test | test <file cat
```

# Teste de estrutura
```bash
quebrando:
echo oi <outfile | wc


cat >test file

# Uso de mais de um redirecionamento em um unico pipe:
cat <infile >outfile | wc -l
cat <infile >>outfile | wc -l
cat <<EOF >outfile
cat <<EOF >>outfile
```

# Test for here_doc
```bash
faaraujo@c2r3s3:~/00/shell$ cat << ""
> ola
> 
ola
faaraujo@c2r3s3:~/00/shell$ cat << ""
> 
faaraujo@c2r3s3:~/00/shell$ cat << "ola"    
> "ola"
> ola
"ola"
```

# Test fo $1, $@, $*, $#, $0
```bash
faaraujo@c2r3s3:~/00/shell$ $#
0: command not found
faaraujo@c2r3s3:~/00/shell$ $?
127: command not found
faaraujo@c2r3s3:~/00/shell$ $1
faaraujo@c2r3s3:~/00/shell$ $@
faaraujo@c2r3s3:~/00/shell$ ls $1
dcs  includes  libft  LICENSE  Makefile  minishell  README.md  src  supp.supp
faaraujo@c2r3s3:~/00/shell$ ls $@
dcs  includes  libft  LICENSE  Makefile  minishell  README.md  src  supp.supp
```
# Linha de comando
```bash
<<Makefile cat| echo "$PWD <$?> | 'hola'" "$HOME"/src | echo $? '$?' |'tr' -d / >outfile
'"$SHELL"'"$SHELL"
$HOME' '$USER' >>>" '$PWD' $SHELL #Caso de quebra
echo "hello  '  there" how are 'you 'doing? $USER |wc -l >outfile
echo "$PWD < > \\ | 'hola'" ~/src ${USER} $HOME |'tr' -d / >outfile
echo|cat || teste >>>> >>ts >>>tdb ||t
echo "$HOME '$PWD' >>>" $USER '$PWD' ~///fal
<<$USER "$PWD '$USER'u | $'USER' 'hola'" ~/src '$USER' $HOME|'tr' -d / >outfile
$USER '$USER'  4 $ $'USER' $  "SHELL" "$SHELL"   $    $
<<Makefile cat| echo \"$PWD < > | 'hola'\" $USER || 'tr' -d / >outfile
```

## Syntax errors
```bash

 cat ""

$? = 1
input$ test
output$ '\n'

###############################################
# bash: syntax error near unexpected token `|'#
###############################################
$? = 2
|test ok
 | test ok
| < test ok
| << test ok
| > test ok
| >> test ok
| test ok

< | test ok
<< | test ok
> | test ok
>> | test ok


echo hi | | echo hi ok
echo hi ||| echo hi ok
command1 | | command2 ok

echo hi | ok
> 
bash: syntax error: unexpected end of file

#####################################################
# bash: syntax error near unexpected token `newline'#
#####################################################

$? = 2
< ok
<< ok
> ok
>> ok
test | >   ok
test | >>   ok
test | < ok
echo > ok
echo >> ok
echo < ok
echo << ok

#####################################################
# bash: syntax error near unexpected token `>>'     #
#####################################################

$ echo >>>
$ echo >>>>
$ echo >>>>>>>>>>>>>>
bash: syntax error near unexpected token `>'

$ <<<
$ <<<<
$ <<<<<<<<<<<
bash: syntax error near unexpected token `<'

bash: syntax error near unexpected token `<'
echo hi >< file

bash: syntax error near unexpected token `>'
echo hi <> file

$? = 2
bash: syntax error near unexpected token `>'
ls > > output.txt
#####################################################



echo "Hello World'
echo 'Single Quotes"
echo "Hello, world
> 
bash: unexpected EOF while looking for matching `"'
bash: syntax error: unexpected end of file

# NAO LIDAR
echo $(ls -l
> 
bash: unexpected EOF while looking for matching `)'
bash: syntax error: unexpected end of file

###################
# Executor errors #
###################

$? = 127
cmnd_not_exist arg1 arg2
cmnd_not_exist: command not found

"|" test
'|' test
|: command not found

$? = 0
echo $UndefinedVariable
'/n'

$? = 1
cat < input.txt > output.txt
bash: input.txt: No such file or directory

$? = 1
result=$((10 + ))
bash: 10 + : syntax error: operand expected (error token is "+ ")

#############################################

$? = 0
echo hiecho hi
echo hi|echo hi
echo hi |echo hi
echo hi| echo hi
echo hi| echo hi | echo hi| echo hi

##########
# output:#
##########

hiecho hi
hi
hi
hi
hi
```

# Expansão de variáveis ${}
```bash
shell$ echo $!USER
USER
shell$ echo ${!USER}
(null)
shell$ echo ${USER}
fal
shell$ echo ${USER}Colchete protege a variavel
falColchete protege a variavel
shell$ echo ${ty-test} # Se ty não estiver definido, imprime test
test
shell$ echo ${USER-test}
fal
```


```bash
 <Makefile cat| echo "$PWD 'hola'" ~/src | 'tr' -d / >outfile
```

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
