package com.example.academico.controller;
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

import com.example.academico.model.entity.Aluno;
import com.example.academico.model.repositiry.AlunoRepository;


@RestController
@RequestMapping("api/alunos")
public class AlunoController {
	@Autowired
	private AlunoRepository alunoRepository;
	
	//listar todos
	@GetMapping	
	public List<Aluno> listAll(){
		List<Aluno> alunos = alunoRepository.findAll();
		return alunos;
	}
	
	//inclusão
	@PostMapping
	public Aluno insert(@RequestBody Aluno aluno) {
		return alunoRepository.save(aluno);
	}
	
	//exclusão
	@DeleteMapping("/{id}")
	public String delete(@PathVariable Integer id) {
		alunoRepository.deleteById(id);
		return "Excluido com sucesso!!!";
	}
	
	//consulta
	@GetMapping("/{id}")
	public Aluno getById(@PathVariable Integer id) {
		return alunoRepository.findById(id).get();
	}
	
	//inclusão
	@PutMapping("/{id}")
	public Aluno getById(@RequestBody Aluno aluno, @PathVariable Integer id) {
		
		//Pesquiso o aluno
		Aluno alunoUpdate = alunoRepository.findById(id).get();
		
		//altero o aluno
		alunoUpdate.setNome(aluno.getNome());
		alunoUpdate.setEmail(aluno.getEmail());
		alunoUpdate.setEndereco(aluno.getEndereco());
		alunoUpdate.setDataNascimento(aluno.getDataNascimento());
		alunoUpdate.setPeriodo(aluno.getPeriodo());
		
		//atualizo o aluno
		return alunoRepository.save(alunoUpdate);
	}
	
	//listar por nome
	@GetMapping("/nomes/{nome}")
	public List<Aluno> getByNomes(@PathVariable String nome){
		return alunoRepository.findByNomeStartsWith(nome);
	}
	
	//pesquisar por nome
	@GetMapping("/nome/{nome}")
	public Aluno getByNome(@PathVariable String nome) {
		Aluno alu = alunoRepository.findByNome(nome);
		return alu;
	}
}
