package com.lojabrinquedos.fantasystar.controller.web;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

import com.lojabrinquedos.fantasystar.model.entity.Brinquedo;
import com.lojabrinquedos.fantasystar.model.repository.BrinquedoRepository;

@Controller
@RequestMapping("categorias")
public class CategoriaWebController {
    
    @Autowired
    private BrinquedoRepository brinquedoRepository;

    @GetMapping("/pesquisar/{categoria}")
    public String searchByCategoria(Model model, @PathVariable String categoria){
        List<Brinquedo> brinquedos = brinquedoRepository.findByCategoriaContains(categoria);
        model.addAttribute("brinquedos", brinquedos);
        model.addAttribute("categoria", categoria);
        return "catalogo";
    }
}
