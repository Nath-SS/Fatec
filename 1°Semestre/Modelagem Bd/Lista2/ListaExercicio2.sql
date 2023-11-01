create database bdFuncionarios;

use bdFuncionarios;

create table tbFuncionario (
	idFuncionario int primary key auto_increment
    , nomeFuncionario varchar(100) not null
    , departamento varchar(50)
    , funcao varchar(50)
    , salario decimal(10,2)

);

describe tbFuncionario;
describe tbFuncionario idFuncionario;

insert into tbFuncionario(NomeFuncionario, departamento, funcao, salario)
	values	('Carlos Alberto', '3', 'vendedor', 1350.00),
			('Marcos Henrique', '2', 'gerente', 1985.00),
            ('Aparecida Silva', '3', 'secretaria', 1200.50),
			('Jaciba da Silva', '3', '', 1500.00),
            ('Wilson de Macedo', '3', 'pprogramador', 1050.00),
            ('Augusto Souza', '3', 'programador', 1050.00);

select * from tbFuncionario;
            
select nomeFuncionario as nome, idFuncionario as codigo from tbFuncionario where departamento = '3'
	order by nome;

set sql_safe_updates = 0;

update tbFuncionario set salario = 2300.56 where idfuncionario = 3;
update tbFuncionario set departamento = '5' where nomeFuncionario = 'Aparecida Silva';
update tbFuncionario set salario = salario*1.10;

select * from tbFuncionario;

delete from tbFuncionario where departamento = '2';
delete from tbFuncionario where nomeFuncionario = 'Augusto Souza';

/* truncate table tbFuncionario ----- exclui todos os registros da tabela */

alter table tbFuncionario add admissao date;

update tbFuncionario set admissao = '2006-01-15' where idFuncionario = 1;
update tbFuncionario set admissao = '1999-10-21' where idFuncionario = 3;
update tbFuncionario set admissao = '2004-10-21' where idFuncionario = 4;
update tbFuncionario set admissao = '2006-04-26' where idFuncionario = 5;

select * from tbFuncionario;

select nomeFuncionario as nome, admissao from tbFuncionario where month(admissao) = 10;
select nomeFuncionario as nome, admissao from tbFuncionario where admissao >= '2000-01-01';

insert into tbFuncionario(nomeFuncionario, departamento, funcao, salario, admissao) 
	values('Marcos Henrique', '2', 'gerente', 2184.33, '2006-05-25'),
			('Audrey Toledo', '2', 'supervisora', 1700.00, '2006-07-05'),
			('Sandra Manzano', '2', 'analista', 2000.00, '2006-07-01'),
			('Marcio Canuto', '2', 'programador', 1200.00, '2006-07-10');
                                
select * from tbFuncionario;

/* OPERAÇÕES ARITMÉTICAS */

select * from tbFuncionario where departamento = '5';
select * from tbFuncionario where funcao = 'vendedor';
select * from tbFuncionario where salario <= 1700;
select * from tbFuncionario where salario > 1700+50;
select * from tbFuncionario where salario > (1700+50);


select * from tbFuncionario where departamento = '3' and funcao = 'programador'; 
select * from tbFuncionario where departamento = '3' or departamento = '5';
select * from tbFuncionario where not funcao = 'vendedor';
select * from tbFuncionario where departamento = '3' xor funcao = 'programador';

alter table tbFuncionario add filhos smallint;
select nomeFuncionario as funcionario, filhos as filhos from tbFuncionario where filhos is null;

update tbFuncionario set filhos = 1 where idFuncionario = 1;
update tbFuncionario set filhos = 3 where idFuncionario = 3;
update tbFuncionario set filhos = 2 where idFuncionario = 5;
update tbFuncionario set filhos = 1 where idFuncionario = 4;

select * from tbFuncionario where salario between 1700 and 2000;
select * from tbFuncionario where not salario between 1700 and 2000;
select * from tbFuncionario where departamento in ('2', '3');
select * from tbFuncionario where not departamento in ('2', '3');

select * from tbFuncionario where nomeFuncionario like 'a%';
select * from tbFuncionario where nomeFuncionario like '_a%';
select * from tbFuncionario where nomeFuncionario like '%an%';
select * from tbFuncionario where salario like '%6';
select * from tbFuncionario where salario like '_5%2';
select * from tbFuncionario where nomeFuncionario not like '%an%';

select nomeFuncionario as Funcionario, salario as Salario from tbFuncionario where salario like '%1%';
 

 



              
