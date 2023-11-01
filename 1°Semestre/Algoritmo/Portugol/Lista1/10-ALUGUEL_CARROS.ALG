Algoritmo "10-aluguel_carros"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 28/09/2022
Var
// Seção de Declarações das variáveis 
km , diaalugado , gastodia, kmrodado, total: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
escreval ("qual quantidade de km pecorridos?")
leia(km)
escreval ("quantos dias alugados?")
leia(diaalugado)
gastodia <- diaalugado * 150,00
kmrodado <- km + 0,50
total <- gastodia + kmrodado
escreval ("o valor do dia é de: " , gastodia)
escreval ("o valor dos km é de: ", kmrodado)
escreval ("o total a pagar é de:", total)

Fimalgoritmo