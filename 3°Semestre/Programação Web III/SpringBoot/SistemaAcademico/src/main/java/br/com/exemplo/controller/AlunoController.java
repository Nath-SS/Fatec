package br.com.exemplo.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import br.com.exemplo.model.entity.Aluno;
import br.com.exemplo.model.repository.AlunoRepository;


/*
 * GET        /api/alunos      -> listAll()
 * GET        /api/alunos/1    -> getById()
 * POST       /api/alunos      -> insert()
 * PUT        /api/alunos/1    -> update()
 * DELETE     /api/alunos/1    -> delete()
 */

@RestController
@RequestMapping("api/alunos")
public class AlunoController {

	@Autowired
	private AlunoRepository alunoRepository;
	
	@GetMapping
	public List<Aluno> listAll(){
		List<Aluno> alunos = alunoRepository.findAll();
		return alunos;
	}
	
	@GetMapping("/{id}")
	public Aluno getById(@PathVariable("id") Integer id ) {
		Aluno aluno = alunoRepository.findById(id).get();
		return aluno;
	}
	
	@PostMapping
	public Aluno insert(@RequestBody Aluno aluno){
		return alunoRepository.save(aluno);
	}
	
	@PutMapping("/{id}")
	public Aluno update(@RequestBody Aluno aluno, @PathVariable Integer id){
		// obter o aluno a ser atualizado
		Aluno alunoUpdate = alunoRepository.findById(id).get();
		// atualizar os dados
		alunoUpdate.setNome(aluno.getNome());
		alunoUpdate.setEndereco(aluno.getEndereco());
		alunoUpdate.setEmail(aluno.getEmail());
		alunoUpdate.setDataNascimento(aluno.getDataNascimento());
		alunoUpdate.setPeriodo(aluno.getPeriodo());
		alunoRepository.save(alunoUpdate);
		
		return alunoUpdate; 
	}

	@DeleteMapping("/{id}")
	public String delete(@PathVariable Integer id) {
		alunoRepository.deleteById(id);
		return "Aluno Excluído com Sucesso!";
	}
	
	@GetMapping("/nome/{nome}")
	public Aluno getByNome(@PathVariable String nome) {
		Aluno alu = alunoRepository.findByNome(nome);
		return alu;
	}
	
	@GetMapping("/primeiro-nome/{nome}")
	public List<Aluno> getByPrimeiroNome(@PathVariable String nome) {
		List<Aluno> alunos = alunoRepository.findByNomeStartsWith(nome);
		return alunos;
	}
	
	@GetMapping("/ultimo-nome/{nome}")
	public List<Aluno> getByUltimoNome(@PathVariable String nome) {
		List<Aluno> alunos = alunoRepository.findByNomeEndsWith(nome);
		return alunos;
	}

	@GetMapping("/contem-nome/{nome}")
	public List<Aluno> getByQualquerNome(@PathVariable String nome) {
		List<Aluno> alunos = alunoRepository.findByNomeContains(nome);
		return alunos;
	}

	
}



