package com.lojabrinquedos.fantasystar.controller.web;

import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import com.lojabrinquedos.fantasystar.model.entity.Brinquedo;
import com.lojabrinquedos.fantasystar.model.repository.BrinquedoRepository;


@Controller
@RequestMapping("/brinquedos")
public class BrinquedoWebController {

	
	@Autowired
	private BrinquedoRepository brinquedoRepository;
	
    //-------------testados-------------//
	//--------Listar os brinquedos por um nome especifico
	@GetMapping("/pesquisar") 
	public String searchByName(Model model, @RequestParam String filtroNome) {
        List<Brinquedo> brinquedos = brinquedoRepository.findByNomeContainsIgnoreCase(filtroNome);
        model.addAttribute("brinquedos", brinquedos);
        model.addAttribute("filtroNome", filtroNome);
        return "redirect:/catalogo";
	}

    //-------------pra testar-------------//
	
    //--------Redirecionar para o form de brinquedo
	@Secured("ROLE_ADM")
	@GetMapping("/novo_brinquedo")
	public String newBrinquedo(Model model) {
		
		model
			.addAttribute("brinquedo", new Brinquedo())
			.addAttribute("novo", true);
		
		return "formBrinquedo";
	}

    //--------Adicionar novo brinquedo e retornar para a listagem
	@Secured("ROLE_ADM")
	@PostMapping("/adicionar_brinquedo")
	public String saveBrinquedo(Brinquedo brinquedo, @RequestParam MultipartFile ftFile) {
		try {
			//receber imagem
			String nomeImagem = ftFile.getOriginalFilename();
			String caminhoImagem = "/image/";

			//salvar imagem no diretório
			File arquivo = new File(caminhoImagem + nomeImagem);
			ftFile.transferTo(arquivo);

			//salvar no objeto
			brinquedo.setNomeImagem(ftFile.getOriginalFilename());
			brinquedo.setCaminhoImagem(caminhoImagem + nomeImagem);

			//salvar no banco
			brinquedoRepository.save(brinquedo);
			return "redirect:/catalogo";
		} catch (IllegalStateException e) {
			e.printStackTrace();
			return "redirect:/catalogo";
		} catch (IOException e) {
			e.printStackTrace();
			return "redirect:/catalogo";
		}

		
	}
	
    //--------Deletar por id e retornar para listagem
	@Secured("ROLE_ADM")
	@GetMapping("/deletar_brinquedo")
	public String deleteBrinquedo(@RequestParam String id) {
		Optional<Brinquedo> brinquedoId = brinquedoRepository.findById(id);
		if (brinquedoId.isPresent()) 
			brinquedoRepository.deleteById(id);
		
		return "redirect:/catalogo";
	}
	
	@Secured("ROLE_ADM")
	@GetMapping("/editar_brinquedo")
	public String editBrinquedo(Model model, @RequestParam String id) {
		
		Brinquedo aluno = brinquedoRepository.findById(id).get();
		
		model
			.addAttribute("aluno", aluno)
			.addAttribute("novo", false);
		
		return "formBrinquedo";
	}
	
	
	
}
