Algoritmo "IMC"
// Disciplina  : [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 21/09/2022
Var
// Se��o de Declara��es das vari�veis 
   IMC, altura, peso: real

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   Escreval("***Programa de Indice de Massa Corporea***")
   Escreval("Digite o seu peso")
   Leia(peso)
   Escreval("Digite sua altura")
   Leia(altura)
   IMC<-peso/(altura)^2
   Escreval("O IMC �:")
   Escreval(IMC)
   Se(IMC<18.5)Ent�o
         Escreval("Magreza")
   fimse
   se((IMC>=18.5) e (IMC<24.9))Ent�o
         Escreval("Peso normal")
   fimse
   se((IMC>=25) e (IMC<29.9))Ent�o
         Escreval("Sobrepeso")
   fimse
   se((IMC>30) e (IMC<=34.9))Ent�o
         Escreval("Obsidade Grau 1")
   fimse

Fimalgoritmo