Algoritmo "09-salario20p"
// Disciplina   : [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 28/09/2022
Var
// Se��o de Declara��es das vari�veis 
salario, aumento, total: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreval ("qual o seu sal�rio")
leia (salario)

aumento <- (salario * 0.2)
total <- (aumento + salario)

escreval ("salario igual a: ", salario)
escreval ("Aumento igual a: ", aumento)
escreval ("salario atual de: ", total)


Fimalgoritmo