Algoritmo "11-horas_trabalhadas"
// Disciplina   : [Linguagem e Lógica de Programação]
// Professor   : Antonio Carlos Nicolodi 
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 28/09/2022
Var
// Seção de Declarações das variáveis 
nome: caractere
diastrabalhados, pagamento: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 

escreval("qual o nome do funcionário?")
leia(nome)
escreval ("quantos dias trabalhados?")
leia(diastrabalhados)

pagamento <- diastrabalhados * 8 * 50,00

escreval (" o funcionário " , nome , " receberá: " , pagamento)
Fimalgoritmo