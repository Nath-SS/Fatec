package br.com.exemplo.controller.web;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
@RequestMapping("/alunos")
public class AlunoControllerWeb {
	
	@GetMapping("/hello")
	public String index(Model model, @RequestParam("nome") String nome) {
		model.addAttribute("nome", nome);
		return "Index";
	}

}
