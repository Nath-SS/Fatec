Algoritmo "05-conversaoDolar"
// Disciplina   : [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 28/09/2022
Var
// Se��o de Declara��es das vari�veis 
   valorReal, valorDolar, cotacao: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   EscrevaL("Digite a cota��o do dolar")
   leia(cotacao)
   Escreval("Digite o valor em real")
   leia(valorReal)
   valorDolar<-valorReal/cotacao
   Escreval("O valor em dolar �:", valorDolar)

Fimalgoritmo