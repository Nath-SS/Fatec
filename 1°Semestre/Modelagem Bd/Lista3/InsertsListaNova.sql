
insert into tbdepartamento(nomeDepartamento, localizacao)
	values ('familiaHJ2' , 'Setor 13'),
			('PrintalCGI' , 'Setor 6'),
			('FonteFamily' , 'Setor 5'),
			('courrai' , 'Setor 4'),
			('CGIdream' , 'Setor 3'),
			('Mantra' , 'Setor 2'),
			('Pessoal' , 'Setor 1');
        
insert into tbfuncionarios(idDepartamento, primeiroNome, segundoNome, ultimoNome, nascimento, cpf, rg, endereço, cep, cidade, telefone, funcao, salario)
	values (1, 'pedro', 'paulo', 'pedroso', '2000-07-11' , '000.000.000-12', '00.000.000-X', 'rua patolina', '29704-495', 'São Paulo', '11923455555', 'repositor', 1800.00),
			(2, 'marilia', 'pedrosa', 'franca', '2000-06-11' , '000.000.000-13', '00.000.000-1', 'rua 1', '29704-495', 'São Paulo', '11923455555', 'motorista' , 980.00),
			(3, 'fabio', 'pedrosa', 'dias', '2000-05-11' , '000.000.000-14', '00.000.000-2', 'rua 2', '29704-495', 'Recife' , '11923455555' , 'telefonista' , 1300.00),
			(4, 'pocah', 'borges', 'silva', '2000-04-11' , '000.000.000-15', '00.000.000-3', 'rua 3', '29704-495', 'São Paulo', '11923455555' , 'divisor' , 1144.00),
			(5, 'pietra', 'maria', 'santos', '2000-02-11' , '000.000.000-16', '00.000.000-4', 'rua 4', '29704-495', 'Recife', '11923455555' , 'corretor' , 1400.00),
			(6, 'pedro', 'guiver', 'lima', '2000-09-11' , '000.000.000-17', '00.000.000-5', 'rua 6', '29704-495', 'Recife', '11923455555' , 'supervisor' , 2300.00),
			(7, 'paula', 'tejano', 'silva', '2000-08-11' , '000.000.000-18', '00.000.000-7', 'rua 5', '29704-495', 'São Paulo' , '11923455555' , 'vendedor' , 1250.00);

insert into tbgerente(idDepartamento, primeiroNome, segundoNome, ultimoNome, nascimento, cpf, rg, endereço, cep, cidade, telefone, salario)
	values (1, 'marcos', 'paulo', 'pedroso', '2000-07-31' , '000.000.000-12', '00.000.000-X', 'rua patolina', '29704-495', 'Recife', '11923455555', 3000.00),
			(2, 'matheus', 'borges', 'oliveira', '2000-06-30' , '000.000.000-13', '00.000.000-1', 'rua 1', '29704-495', 'Recife', '11923455555', 2200.00),
			(3, 'bruna', 'freitas', 'passos', '2000-05-16' , '000.000.000-14', '00.000.000-2', 'rua 2', '29704-495', 'São Paulo', '11923455555', 1900.00),
			(4, 'phabio', 'alvez', 'maria', '2000-04-15' , '000.000.000-15', '00.000.000-3', 'rua 3', '29704-495', 'Recife', '11923455555', 2000.00),
			(5, 'carla', 'silva', 'maia', '2000-02-14' , '000.000.000-16', '00.000.000-4', 'rua 4', '29704-495', 'São Paulo', '11923455555', 2500.00),
			(6, 'fabiana', 'bispo', 'natal', '2000-09-12' , '000.000.000-17', '00.000.000-5', 'rua 6', '29704-495', 'Recife', '11923455555', 1700.00),
			(7, 'paulo', 'henrique', 'alvez', '2000-08-31' , '000.000.000-18', '00.000.000-7', 'rua 5', '29704-495', 'São Paulo', '11923455555', 3300.00);
        