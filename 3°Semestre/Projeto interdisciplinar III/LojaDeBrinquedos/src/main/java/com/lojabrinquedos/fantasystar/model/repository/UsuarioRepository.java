package com.lojabrinquedos.fantasystar.model.repository;

import org.springframework.data.mongodb.repository.MongoRepository;
import com.lojabrinquedos.fantasystar.model.entity.Usuario;

public interface UsuarioRepository extends MongoRepository<Usuario, String> {

}
