package com.lojabrinquedos.fantasystar.controller.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;

import com.lojabrinquedos.fantasystar.model.entity.Usuario;
import com.lojabrinquedos.fantasystar.model.repository.UsuarioRepository;
import com.lojabrinquedos.fantasystar.service.UserService;



@Controller
@RequestMapping("/user")
public class UsuarioWebController {
    
    @Autowired
    private UsuarioRepository usuarioRepository;

    @Autowired
    private UserService userService;

    //Utilizando SpringSecurity

    //---------Redirecionar form de signin
    @GetMapping("/signin")
    public String signin(Model model){
        model.addAttribute("usuario", new Usuario());
        return "signin";
    }

    //---------Cadastrar e redirecionar para o signin
    @PostMapping("/cadastrar")
    public String cadastrar(Model model, @RequestBody Usuario usuario){
        Usuario resultado = userService.registerUser(usuario);
        if(resultado != null){
            return "login";
        }else{
            model.addAttribute("mensagemErro", "desculpe houve algum problema");
            return "signin";
        }
    }

    //---------Redirecionar form de login
    @GetMapping("/login")
    public String login(Model model){
        model.addAttribute("usuario", new Usuario());
        return "login";
    }

    //---------Logar e redirecionar para o perfil
    @PostMapping("/logar")
    public String logar(Model model, @RequestBody Usuario usuario){
        Usuario verificacao = usuarioRepository.findByEmailAndSenhaContains(usuario.getEmail(), usuario.getSenha());
        if(verificacao != null){
            userService.loadUserByUsername(verificacao.getEmail());
            return "redirect:/user/perfil/" + verificacao.getNome();
        }else{
            model.addAttribute("mensagemErro", "desculpe houve algum problema");
            return "login";
        }
    }

    @GetMapping("/perfil/{nome}")
    public String perfil(Model model, @PathVariable String nome){
        Usuario usuario = usuarioRepository.findByNome(nome);
        model.addAttribute("usuario", usuario);

        return "perfil";
    }



    




    /* 
    //Utilizando session
    //---------Redirecionar form de login
    @GetMapping("/login")
    public String login(Model model){

        model.addAttribute("usuario", new Usuario());
        return "login";
            
    }
    //---------Logar e redirecionar para o perfil
    @PostMapping("/logar")
    public String logar(Model model, HttpSession session, @RequestParam String email, String senha){
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
    */

}
