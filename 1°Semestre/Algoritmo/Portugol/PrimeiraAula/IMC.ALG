Algoritmo "IMC"
// Disciplina  : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 21/09/2022
Var
// Seção de Declarações das variáveis 
   IMC, altura, peso: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   Escreval("***Programa de Indice de Massa Corporea***")
   Escreval("Digite o seu peso")
   Leia(peso)
   Escreval("Digite sua altura")
   Leia(altura)
   IMC<-peso/(altura)^2
   Escreval("O IMC é:")
   Escreval(IMC)
   Se(IMC<18.5)Então
         Escreval("Magreza")
   fimse
   se((IMC>=18.5) e (IMC<24.9))Então
         Escreval("Peso normal")
   fimse
   se((IMC>=25) e (IMC<29.9))Então
         Escreval("Sobrepeso")
   fimse
   se((IMC>30) e (IMC<=34.9))Então
         Escreval("Obsidade Grau 1")
   fimse

Fimalgoritmo