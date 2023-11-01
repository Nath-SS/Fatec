use locadora;

#1
select count(cod_copia) as 'Qntd copias' from copias;

#2
select count(cod_copia) as 'Qntd copias', cod_tipomidia as 'Tipo Midia' from copias
group by cod_tipomidia;

#3
select count(cod_copia) as 'Qntd copias', nome_titulo as 'Titulo' from copias
join titulo on copias.cod_titulo = titulo.cod_titulo
group by nome_titulo order by count(cod_copia) desc;

#4
select distinct * from tipomidia;

#5
select count(data_venda) as 'Qntd vendas' from venda;

#6
select cliente.cod_cliente as 'Código', nome as 'Nome cliente', count(venda.cod_cliente) as 'Qntd compras' from venda
join cliente on venda.cod_cliente = cliente.cod_cliente
group by nome; 

#7a
select distinct municipio from loja;

#7b
select distinct ano_producao as 'Ano' from titulo order by ano_producao desc;

#7c
select distinct uf as 'Estados com loja' from loja;

#8
select distinct uf as 'Estado', count(cod_loja) as 'Qntd lojas' from loja
group by uf;

#9 o comando Having é usado em acompanhamento com o comando Group By, impondo uma condição para aquela agrupação
select distinct cod_cliente as 'Código Cliente', count(cod_cliente) as 'Qntd compras' from venda
group by cod_cliente having count(cod_cliente) > 1;

#10 o comando Limit é usado para limitar o número de dados retornados, usarei o exemplo acima para demonstrar
select distinct cod_cliente as 'Código Cliente', count(cod_cliente) as 'Qntd compras' from venda
group by cod_cliente
having count(cod_cliente) > 1
limit 4;