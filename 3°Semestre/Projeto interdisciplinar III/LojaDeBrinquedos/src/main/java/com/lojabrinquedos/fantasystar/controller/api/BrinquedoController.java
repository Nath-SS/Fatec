package com.lojabrinquedos.fantasystar.controller.api;


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

import com.lojabrinquedos.fantasystar.model.entity.Brinquedo;
import com.lojabrinquedos.fantasystar.model.repository.BrinquedoRepository;


@RestController
@RequestMapping("api/brinquedos")
public class BrinquedoController {

	@Autowired
	private BrinquedoRepository brinquedoRepository;

	@GetMapping
	public List<Brinquedo> listAll(){
		List<Brinquedo> brinquedos = brinquedoRepository.findAll();
		return brinquedos;
	}

	@GetMapping("/pesquisa/{nome}")
	public List<Brinquedo> getContains(@PathVariable String nome){
		List<Brinquedo> brinquedoss = brinquedoRepository.findByNomeContains(nome);
		return brinquedoss;
	}
	
	@PostMapping("/adicionar")
	public Brinquedo insert(@RequestBody Brinquedo brinquedo){
		return brinquedoRepository.save(brinquedo);
	}

	@PutMapping("/atualizar/{id}")
	public Brinquedo update(@RequestBody Brinquedo brinquedo, @PathVariable String id){
		Brinquedo brinquedoUpdate = brinquedoRepository.findById(id).get();
		
		brinquedoUpdate.setNome(brinquedo.getNome());
		brinquedoUpdate.setCategoria(brinquedo.getCategoria());
		brinquedoUpdate.setPreco(brinquedo.getPreco());
		brinquedoUpdate.setQntd(brinquedo.getQntd());
		brinquedoUpdate.setDescricao(brinquedo.getDescricao());
		brinquedoRepository.save(brinquedoUpdate);
		
		return brinquedoUpdate; 
	}

	//como caralhos vou lembrar daquele id gigantesco?
	@DeleteMapping("/deletar/{id}")
	public String delete(@PathVariable String id){
		brinquedoRepository.deleteById(id);
		return "brinquedo excluido com sucesso";
	}

	@DeleteMapping("/deletar/{nome}")
	public String deleteByNome(@PathVariable String nome){
		brinquedoRepository.deleteByNome(nome);
		return "brinquedo excluido com sucesso";
	}
}
