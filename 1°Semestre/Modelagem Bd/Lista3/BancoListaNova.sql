create database bdEmpresa;

use bdEmpresa;

create table tbDepartamento(
	idDepartamento int primary key auto_increment
    , nomeDepartamento varchar(30) not null
    , localizacao varchar(8)
);

create table tbGerente(
	idGerente int primary key auto_increment
    , idDepartamento int
	, primeiroNome varchar(100) not null
    , segundoNome varchar(100)
    , ultimoNome varchar(100)
    , nascimento date
    , cpf varchar(14) not null
    , rg varchar(14) not null
    , endereço varchar(100)
    , cep varchar(20) not null
    , cidade varchar(100)
    , telefone varchar(20)
    , salario decimal(10,2)
    , foreign key(idDepartamento) references tbDepartamento(idDepartamento)

);

create table tbFuncionarios(
	idFuncionarios int primary key auto_increment
    , idDepartamento int
    , primeiroNome varchar(100) not null
    , segundoNome varchar(100)
    , ultimoNome varchar(100)
    , nascimento date
    , cpf varchar(14) not null
    , rg varchar(14) not null
    , endereço varchar(100)
    , cep varchar(20) not null
    , cidade varchar(100)
    , telefone varchar(20)
    , funcao varchar (30)
    , salario decimal(10,2)
    , foreign key(idDepartamento) references tbDepartamento(idDepartamento)

);



/*
select * from tbDepartamento;
select * from tbFuncionarios;
select * from tbGerente;
*/