package com.lojabrinquedos.fantasystar.controller.web;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import com.lojabrinquedos.fantasystar.model.entity.Brinquedo;
import com.lojabrinquedos.fantasystar.model.entity.Usuario;
import com.lojabrinquedos.fantasystar.model.repository.BrinquedoRepository;

import jakarta.servlet.http.HttpSession;

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
    public String admPage(Model model, HttpSession session){
        Usuario user = (Usuario) session.getAttribute("usuario");
        if(user != null){
            if(user.isAdm()){
                return "administracao";
            }else{
                model.addAttribute("semAcesso", "você não possui acesso para acessar essa página");
                return "redirect:/";
            }
        }else{
            return "redirect:/user/login";
        }
    }

    @GetMapping("sobre")
    public String sobrePage(){
        return "sobre";
    }


}
