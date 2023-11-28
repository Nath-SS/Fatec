package com.lojabrinquedos.fantasystar.model.repository;

import java.util.List;

import org.springframework.data.mongodb.repository.MongoRepository;
import com.lojabrinquedos.fantasystar.model.entity.Usuario;

public interface UsuarioRepository extends MongoRepository<Usuario, String> {

    Usuario deleteByNome(String nome);

    Usuario findByNome(String nome);

    List<Usuario> findByNomeContains(String nome);

    List<Usuario> findByEmail(String email);

    Usuario findByEmailAndSenhaContains(String email, String senha);

    

}
