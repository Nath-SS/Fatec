Algoritmo "12-jokenpo"
// Disciplina   : [Linguagem e L�gica de Programa��o]
// Professor   : Antonio Carlos Nicolodi 
// Descri��o   : Aqui voc� descreve o que o programa faz! (fun��o)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 28/09/2022
Var
// Se��o de Declara��es das vari�veis 
   jogada, pc: inteiro

Inicio
// Se��o de Comandos, procedimento, fun��es, operadores, etc... 
   Escreval("***-Jokenpo-***")
   Escreval("Digite uma das op��es abaixo)
   Escreval("0 - Pedra")
   Escreval("1 - Papel")
   Escreval("2 - Tesoura")
   Escreval("")
   Escreval("Qual sua jogada?")
   leia(jogada)
   timer(300)
   Escreval("***-Jokenpo-***")
   timer(0)
   pc<-randi(3)
   escolha pc
           caso 0
            Escreval("Computador jogou pedra")
           caso 1
            Escreval("Computador jogou papel")
           caso 2
            Escreval("Computador jogou tesoura")
           outrocaso
   fimescolha
   escolha jogada
           caso 0
            Escreval("Voc� jogou pedra")
           caso 1
            Escreval("Voc� jogou papel")
           caso 2
            Escreval("Voc� jogou tesoura")
           outrocaso
            Escreval("Jogada inv�lida")
   fimescolha
   Escreval("=============")
   se (pc = 0) e (jogada = 0) ent�o
      Escreval("Empate")
   sen�o
   se(pc = 0) e (jogada = 1) ent�o
      Escreval("jogador venceu")
   sen�o
   se(pc = 0) e (jogada = 2) ent�o
      Escreval("computador venceu")
      fimse
   fimse
           

Fimalgoritmo