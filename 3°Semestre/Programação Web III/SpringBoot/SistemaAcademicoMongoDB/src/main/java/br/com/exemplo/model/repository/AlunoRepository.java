package br.com.exemplo.model.repository;

import java.util.List;

import org.springframework.data.mongodb.repository.MongoRepository;

import br.com.exemplo.model.entity.Aluno;

public interface AlunoRepository extends MongoRepository<Aluno, Integer> {
	
	// pesquisa por nome
	Aluno findByNome(String nome);

	// lista de alunos pelo primeiro nome
	List<Aluno> findByNomeStartsWith(String nome);
	
	// lista de alunos pelo ultimo nome
		List<Aluno> findByNomeEndsWith(String nome);

		// lista de qualquer aluno 
		List<Aluno> findByNomeContains(String nome);	
	
}





