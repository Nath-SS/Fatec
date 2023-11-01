Algoritmo "consumoMedioVeiculo"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nathan Silva Santana
// Data atual  : 25/09/2022
Var
// Seção de Declarações das variáveis 
   Km, Combustivel, Media : real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   Escreval("***Programa de consumo médio de combustivel***")
   Escreval("Digite quantos KM foram percorridos")
   leia(Km)
   Escreval("Digite a quantidade de combustivel gasta")
   leia(Combustivel)
   Media<-Km/Combustivel
   Escreva("Em média o seu consumo de combustivel por km foi: ", Media)

Fimalgoritmo