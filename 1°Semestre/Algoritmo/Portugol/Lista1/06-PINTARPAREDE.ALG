Algoritmo "06-pintarparede"
// Disciplina   : [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 28/09/2022
Var
// Se��o de Declara��es das vari�veis 

altura, comprimento, area, tinta: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc...

escreval("----------------------------")
escreval("Calculo de tintas para pintar")
escreval("----------------------------")
escreval("digite a altura: ")
leia(altura)
escreval("qual o comprimento")
leia(comprimento)
area <- altura * comprimento
tinta <- area / 2
escreval ("O tamanho da area e de: " , area)
escreva ("seria usado", tinta , "litros")





Fimalgoritmo