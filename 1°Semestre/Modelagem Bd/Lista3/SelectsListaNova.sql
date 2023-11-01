use bdEmpresa;

#exercicio 1
select primeiroNome, ultimoNome from tbFuncionarios
order by ultimoNome;

#exercicio 2
select * from tbFuncionarios
order by cidade;

#exercicio 3
select * from tbFuncionarios where salario > 1000
order by primeiroNome, segundoNome, ultimoNome;

#exercicio 4
select nascimento, primeiroNome from tbFuncionarios
order by nascimento desc, primeiroNome;

#exercicio 5
select ultimoNome, primeiroNome, segundoNome, telefone, endereço, cidade from tbFuncionarios
order by ultimoNome, primeiroNome, segundoNome;

#exercicio 6
select sum(salario) as total from tbFuncionarios;

#exercicio 7
select primeiroNome, nomeDepartamento, funcao from tbFuncionarios
join tbDepartamento on tbFuncionarios.idDepartamento = tbDepartamento.idDepartamento
order by primeiroNome;

#exercicio 8
select nomeDepartamento, primeiroNome from tbDepartamento
join tbGerente on tbGerente.idDepartamento = tbDepartamento.idDepartamento
order by nomeDepartamento;

#exercicio 9
select nomeDepartamento, sum(salario) as total from tbDepartamento
join tbFuncionarios on tbFuncionarios.idDepartamento = tbDepartamento.idDepartamento
group by nomeDepartamento;

#exercicio 10
select nomeDepartamento, primeiroNome from tbDepartamento
join tbFuncionarios on tbFuncionarios.idDepartamento = tbDepartamento.idDepartamento
where funcao = "Supervisor"
order by nomeDepartamento;

#exercicio 11
select count(*) as TotalFuncionarios from tbFuncionarios;

#exercicio 12
select AVG(salario) as Media from tbFuncionarios;

#exercicio 13
select nomeDepartamento, min(salario) from tbFuncionarios
join tbDepartamento on tbFuncionarios.idDepartamento = tbDepartamento.idDepartamento
group by nomeDepartamento;

#exercicio 14
select primeiroNome, segundoNome, ultimoNome from tbFuncionarios where segundoNome is Null
order by primeiroNome, ultimoNome;

#exercicio 15
select nomeDepartamento, primeiroNome from tbDepartamento
join tbFuncionarios on tbFuncionarios.idDepartamento = tbDepartamento.idDepartamento
order by nomeDepartamento, primeiroNome;

#exercicio 16
select primeiroNome from tbFuncionarios where cidade = 'Recife' and funcao = 'Telefonista';

#exercicio 17
select primeiroNome from tbFuncionarios
where idDepartamento = (select idDepartamento from tbDepartamento where nomeDepartamento = 'Pessoal');

#exercicio 18
select primeiroNome, nomeDepartamento from tbFuncionarios
join tbDepartamento on tbFuncionarios.idDepartamento = tbDepartamento.idDepartamento
where salario > some(select salario from tbGerente);


