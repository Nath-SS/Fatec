package com.example.academico.model.repositiry;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;

import com.example.academico.model.entity.Aluno;

public interface AlunoRepository extends JpaRepository <Aluno, Integer>{
	
	//pesquisa por nome
	public Aluno findByNome(String nome);
	
	//listar todos por nome
	public List<Aluno> findByNomeStartsWith(String nome);
	
	

}
