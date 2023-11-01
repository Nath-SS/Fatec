Algoritmo "06-pintarparede"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 28/09/2022
Var
// Seção de Declarações das variáveis 

altura, comprimento, area, tinta: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...

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