Algoritmo "mediaNotas"
// Disciplina   : [Linguagem e L�gica de Programa��o]
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 21/09/2022
Var
// Se��o de Declara��es das vari�veis
   NotaA, NotaB, NotaC, resultado: real


Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   Escreval("***Calculo de m�dia de notas***")
   Escreval("Digite sua primeira nota")
   leia(NotaA)
   Escreval("Digite sua segunda nota")
   leia(NotaB)
   Escreval("Digite sua terceira nota")
   leia(NotaC)
   resultado<-(NotaA+NotaB+NotaC)/3
   Escreva("Sua m�dia �: ")
   Escreval(resultado)
   se (resultado<3) ent�o
      Escreval("Reprovado")
   fimse
   se ((resultado>3) e (resultado<5.5)) ent�o
      Escreval("Voc� est� de recupera��o")
   fimse
   se (resultado>6) ent�o
      Escreval("Aprovado")
   fimse
Fimalgoritmo