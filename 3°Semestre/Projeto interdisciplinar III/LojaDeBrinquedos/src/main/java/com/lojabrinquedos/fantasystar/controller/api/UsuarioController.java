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

import com.lojabrinquedos.fantasystar.model.entity.Usuario;
import com.lojabrinquedos.fantasystar.model.repository.UsuarioRepository;

@RestController
@RequestMapping("api/usuarios")
public class UsuarioController {

    @Autowired
    private UsuarioRepository usuarioRepository;

    @GetMapping
    public List<Usuario> listAll(){
        List<Usuario> usuarios = usuarioRepository.findAll();
        return usuarios;
    }

    @GetMapping("/usuario/{nome}")
    public Usuario getByNome(@PathVariable String nome){
        Usuario usuario = usuarioRepository.findByNome(nome);
        return usuario;
    }

    @GetMapping("/usuarios/{nome}")
    public List<Usuario> getByContainsNome(@PathVariable String nome){
        List<Usuario> usuarios = usuarioRepository.findByNomeContains(nome);
        return usuarios;
    }

    // @GetMapping("/usuario/{email}")
    // public List<Usuario> getByEmail(@PathVariable String email){
    //     List<Usuario> usuario = usuarioRepository.findByEmail(email);
    //     return usuario;
    // }

    @PostMapping("/cadastrar")
    public Usuario insert(@RequestBody Usuario usuario){
        return usuarioRepository.save(usuario);
    }

    @PutMapping("/atualizar/{id}")
    public Usuario update(@RequestBody Usuario usuario, @PathVariable String id){
        Usuario usuarioUpdate = usuarioRepository.findById(id).get();

        usuarioUpdate.setNome(usuario.getNome());
        usuarioUpdate.setSenha(usuario.getSenha());
        usuarioUpdate.setEmail(usuario.getEmail());
        usuarioUpdate.setEndereco(usuario.getEndereco());
        usuarioRepository.save(usuarioUpdate);

        return usuarioUpdate;
    }

    @DeleteMapping("/deletar/{id}")
    public String delete(@PathVariable String id){
        usuarioRepository.deleteById(id);
        return "Usuario excluido com sucesso";
    }

    @DeleteMapping("/deletar/{nome}")
    public String deleteByNome(@PathVariable String nome){
        usuarioRepository.deleteByNome(nome);
        return "Usuario excluido com sucesso";
    }
}
