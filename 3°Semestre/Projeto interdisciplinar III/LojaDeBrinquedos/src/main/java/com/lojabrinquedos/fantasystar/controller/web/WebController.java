package com.lojabrinquedos.fantasystar.controller.web;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import com.lojabrinquedos.fantasystar.model.entity.Brinquedo;
import com.lojabrinquedos.fantasystar.model.repository.BrinquedoRepository;



@Controller
@RequestMapping("/")
public class WebController {

    @Autowired
	private BrinquedoRepository brinquedoRepository;
	
    //-------------testados-------------//
    //--------Listar todos os brinquedos
	@GetMapping 
	public String indexPage(Model model) {
		List<Brinquedo> brinquedos = brinquedoRepository.findAll();
		model.addAttribute("brinquedos", brinquedos);
		return "index";
	}

	@GetMapping("catalogo")
	public String catalogoPage(Model model){
		List<Brinquedo> brinquedos = brinquedoRepository.findAll();
		model.addAttribute("brinquedos", brinquedos);
		return "catalogo";
	}
    
    @GetMapping("administração")
    public String admPage(){
        return "administracao";
    }

    @GetMapping("sobre")
    public String sobrePage(){
        return "sobre";
    }


}
