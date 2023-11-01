Algoritmo "mediaNotas"
// Disciplina   : [Linguagem e Lógica de Programação]
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 21/09/2022
Var
// Seção de Declarações das variáveis
   NotaA, NotaB, NotaC, resultado: real


Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   Escreval("***Calculo de média de notas***")
   Escreval("Digite sua primeira nota")
   leia(NotaA)
   Escreval("Digite sua segunda nota")
   leia(NotaB)
   Escreval("Digite sua terceira nota")
   leia(NotaC)
   resultado<-(NotaA+NotaB+NotaC)/3
   Escreva("Sua média é: ")
   Escreval(resultado)
   se (resultado<3) então
      Escreval("Reprovado")
   fimse
   se ((resultado>3) e (resultado<5.5)) então
      Escreval("Você está de recuperação")
   fimse
   se (resultado>6) então
      Escreval("Aprovado")
   fimse
Fimalgoritmo