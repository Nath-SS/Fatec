package com.lojabrinquedos.fantasystar.controller.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import com.lojabrinquedos.fantasystar.model.entity.Usuario;
import com.lojabrinquedos.fantasystar.model.repository.UsuarioRepository;

import jakarta.servlet.http.HttpSession;

@Controller
@RequestMapping("/user")
public class UsuarioWebController {
    
    @Autowired
    private UsuarioRepository usuarioRepository;

    //---------Redirecionar form de login
    @GetMapping("/login")
    public String newLogin(Model model){

        model.addAttribute("usuario", new Usuario());
        return "login";
            
    }
    //---------Logar e redirecionar para o perfil
    @PostMapping("/logar")
    public String login(Model model, HttpSession session, @RequestParam String email, String senha){
        Usuario user = usuarioRepository.findByEmailAndSenhaContains(email, senha);
        if(user != null){
            session.setAttribute("usuario", user);
            session.setAttribute("logado", true);
            return "perfil";
        }else{
            model.addAttribute("mensagemErro", "E-mail ou senha incorretos.");
            return "login";
        }
    }

}
