Algoritmo "09-salario20p"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 28/09/2022
Var
// Seção de Declarações das variáveis 
salario, aumento, total: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreval ("qual o seu salário")
leia (salario)

aumento <- (salario * 0.2)
total <- (aumento + salario)

escreval ("salario igual a: ", salario)
escreval ("Aumento igual a: ", aumento)
escreval ("salario atual de: ", total)


Fimalgoritmo