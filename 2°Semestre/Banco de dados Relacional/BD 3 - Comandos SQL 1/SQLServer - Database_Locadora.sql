create database locadora;
go
use locadora;


create table categoria(
	cod_categoria char(2) primary key not null
	, descricao varchar(40) not null
)

create table loja(
	cod_loja smallint primary key not null
	, nome_loja VARCHAR(40) NOT NULL
	, endereco VARCHAR(40) NOT NULL
	, bairro VARCHAR(40) NOT NULL
	, municipio VARCHAR(40) NOT NULL
	, uf CHAR(2) NOT NULL
)

create table tipomidia(
	cod_tipomidia char(3) primary key not null
	, descricao varchar(40) not null
)

create table titulo(
	cod_titulo int primary key not null
	, nome_titulo varchar(150) not null
	, ano_producao decimal(4,0) not null
	, cod_categoria char(2) foreign key references categoria(cod_categoria)
)

create table cliente(
	cod_cliente smallint primary key not null
	, nome varchar(40) not null
	, fone char(10) not null
	, cod_loja smallint foreign key references loja(cod_loja)
)

create table copias(
	cod_copia smallint primary key not null
	, cod_tipomidia char(3) foreign key references tipomidia(cod_tipomidia)
	, cod_titulo int foreign key references titulo(cod_titulo)
	, status char(1) not null
)

create table venda(
	cod_copia smallint primary key not null
	, data_venda date not null
	, cod_cliente smallint foreign key references cliente(cod_cliente)
)

create table locacao(
	cod_locacao int primary key not null
	, data_locacao date not null
	, cod_cliente smallint foreign key references cliente(cod_cliente)
	, cod_copia smallint foreign key references copias(cod_copia)
)