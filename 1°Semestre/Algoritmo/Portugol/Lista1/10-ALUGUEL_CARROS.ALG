Algoritmo "10-aluguel_carros"
// Disciplina   : [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 28/09/2022
Var
// Se��o de Declara��es das vari�veis 
km , diaalugado , gastodia, kmrodado, total: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
escreval ("qual quantidade de km pecorridos?")
leia(km)
escreval ("quantos dias alugados?")
leia(diaalugado)
gastodia <- diaalugado * 150,00
kmrodado <- km + 0,50
total <- gastodia + kmrodado
escreval ("o valor do dia � de: " , gastodia)
escreval ("o valor dos km � de: ", kmrodado)
escreval ("o total a pagar � de:", total)

Fimalgoritmo