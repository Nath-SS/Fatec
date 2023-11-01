Algoritmo "07-Bhaskara"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 28/09/2022
Var
// Seção de Declarações das variáveis
a, b, c, delta, x1, x2: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc...
//supondo a formula x2 + 2x + 10
  escreval ("Escreva o valor de A")
  leia (a)
  escreval("Escreva o valor de B")
  leia(b)
  escreval("Escreva o valor de C")
  leia(c)
  delta <- b^2 - 4 . a . c
  se (delta > 0 ) entao
     x1 <- ( -b + delta ^ (1/2)) / (2*a)
     x2 <- ( -b - delta ^ (1/2)) / (2*a)
     escreval ("A equação possui duas raizes reais")
     escreva (" x1 = " , x1 , "x2 = " , x2)
  senao se (delta = 0) entao
     x1 <- -b/(2*a)
     escreval(" a equação possui uma raiz ")
     escreval("x=" , x1)
  fimse


Fimalgoritmo