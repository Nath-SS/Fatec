Create database academico;

use academico;

CREATE TABLE alunos (
ra INT(6) UNSIGNED NOT NULL PRIMARY KEY,
nome VARCHAR(50) NOT NULL,
email VARCHAR(50)  NOT NULL,
endereco VARCHAR(50) NOT NULL,
datanascimento DATE NOT NULL,
periodo VARCHAR(20));