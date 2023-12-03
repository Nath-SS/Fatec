package com.lojabrinquedos.fantasystar.service;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import com.lojabrinquedos.fantasystar.model.entity.Usuario;
import com.lojabrinquedos.fantasystar.model.repository.UsuarioRepository;

@Service
public class UserService implements UserDetailsService {

    @Autowired
    private UsuarioRepository usuarioRepository;

    @Autowired
    private BCryptPasswordEncoder passwordEncoder;

    public Usuario registerUser(Usuario usuario) {
        // Verifica se o nome de usuário e email já estão em uso
        if (usuarioRepository.findByNome(usuario.getNome()) != null || usuarioRepository.findByEmail(usuario.getEmail()) != null) {
            throw new RuntimeException("Nome de usuário ou email já em uso");
        }

        // Codifica a senha antes de salvar no banco de dados
        usuario.setSenha(passwordEncoder.encode(usuario.getSenha()));
        return usuarioRepository.save(usuario);
    }

    @Override
    public UserDetails loadUserByUsername(String email) throws UsernameNotFoundException {
        Usuario usuario = usuarioRepository.findByEmail(email);
        if(usuario == null){
            throw new UsernameNotFoundException("Usuário não encontrado com o e-mail: " + email);
        }else{
            List<GrantedAuthority> authorities = new ArrayList<>();
            authorities.add(new SimpleGrantedAuthority("USER"));

            if (usuario.isAdm()) {
                authorities.add(new SimpleGrantedAuthority("ADM"));
            }

            return new org.springframework.security.core.userdetails.User(
                usuario.getNome(),
                usuario.getSenha(), // Considere usar a senha criptografada aqui
                authorities
            );
        }
    }
}
