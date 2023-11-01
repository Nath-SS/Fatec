Algoritmo "05-conversaoDolar"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 28/09/2022
Var
// Seção de Declarações das variáveis 
   valorReal, valorDolar, cotacao: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   EscrevaL("Digite a cotação do dolar")
   leia(cotacao)
   Escreval("Digite o valor em real")
   leia(valorReal)
   valorDolar<-valorReal/cotacao
   Escreval("O valor em dolar é:", valorDolar)

Fimalgoritmo