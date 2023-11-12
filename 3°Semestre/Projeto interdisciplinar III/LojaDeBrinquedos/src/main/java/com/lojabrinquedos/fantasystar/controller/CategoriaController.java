package com.lojabrinquedos.fantasystar.controller;

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

import com.lojabrinquedos.fantasystar.model.entity.Categoria;
import com.lojabrinquedos.fantasystar.model.repository.CategoriaRepository;

@RestController
@RequestMapping("/api/categorias")
public class CategoriaController {

    @Autowired
    private CategoriaRepository categoriaRepository;

    @GetMapping
    public List<Categoria> listAll(){
        List<Categoria> categorias = categoriaRepository.findAll();
        return categorias;
    }

    @PostMapping("/adicionar")
    public Categoria insert(@RequestBody Categoria categoria){
        return categoriaRepository.save(categoria);
    }

    @PutMapping("/atualizar")
    public Categoria update(@RequestBody Categoria categoria, String id){
        Categoria categoriaUpdate = categoriaRepository.findById(id).get();

        categoriaUpdate.setNome(categoria.getNome());
        categoriaUpdate.setDescricao(categoria.getDescricao());
        categoriaRepository.save(categoriaUpdate);

        return categoriaUpdate;
    }

    @DeleteMapping("/deletar/{id}")
	public String delete(@PathVariable String id){
		categoriaRepository.deleteById(id);
		return "categoria excluido com sucesso";
	}

	@DeleteMapping("/deletar/{nome}")
	public String deleteByNome(@PathVariable String nome){
		categoriaRepository.deleteByNome(nome);
		return "categoria excluido com sucesso";
	}

}
