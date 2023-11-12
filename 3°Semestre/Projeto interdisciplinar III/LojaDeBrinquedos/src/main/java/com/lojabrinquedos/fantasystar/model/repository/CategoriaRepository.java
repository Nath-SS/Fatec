package com.lojabrinquedos.fantasystar.model.repository;

import org.springframework.data.mongodb.repository.MongoRepository;
import com.lojabrinquedos.fantasystar.model.entity.Categoria;;

public interface CategoriaRepository extends MongoRepository<Categoria, String> {
    
    Categoria deleteByNome(String nome);

}
