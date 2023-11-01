use locadora;

#1
select nome_titulo as Titulo, ano_producao as Ano from titulo 
order by nome_titulo; 

#2
select * from titulo where cod_categoria = 'AC'; 

#3
select nome_loja as Nome, municipio as Municipio, uf as UF from loja 
order by uf desc; 

#4
select * from cliente where  nome like 'D%' 
order by nome asc; 

#5
select * from loja where uf = 'SP' and nome_loja like '%ra%'; 

#6
select * from titulo where ano_producao < 1958 
order by ano_producao asc; 

#7
select * from titulo where ano_producao > 1928 and ano_producao < 1944 
order by ano_producao;

#8
select * from titulo where cod_categoria = 'AC' or cod_categoria = 'DR' 
order by cod_categoria, nome_titulo;

#9
select distinct ano_producao as Ano from titulo; 

#10
select * from titulo where cod_categoria = 'CM' and ano_producao > 1964 and ano_producao < 1991 
order by nome_titulo asc;
