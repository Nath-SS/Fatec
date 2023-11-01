Algoritmo "12-jokenpo"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 28/09/2022
Var
// Seção de Declarações das variáveis 
   jogada, pc: inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   Escreval("***-Jokenpo-***")
   Escreval("Digite uma das opções abaixo)
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
            Escreval("Você jogou pedra")
           caso 1
            Escreval("Você jogou papel")
           caso 2
            Escreval("Você jogou tesoura")
           outrocaso
            Escreval("Jogada inválida")
   fimescolha
   Escreval("=============")
   se (pc = 0) e (jogada = 0) então
      Escreval("Empate")
   senão
   se(pc = 0) e (jogada = 1) então
      Escreval("jogador venceu")
   senão
   se(pc = 0) e (jogada = 2) então
      Escreval("computador venceu")
      fimse
   fimse
           

Fimalgoritmo