Algoritmo "11-horas_trabalhadas"
// Disciplina   : [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 28/09/2022
Var
// Se��o de Declara��es das vari�veis 
nome: caractere
diastrabalhados, pagamento: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 

escreval("qual o nome do funcion�rio?")
leia(nome)
escreval ("quantos dias trabalhados?")
leia(diastrabalhados)

pagamento <- diastrabalhados * 8 * 50,00

escreval (" o funcion�rio " , nome , " receber�: " , pagamento)
Fimalgoritmo