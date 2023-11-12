package com.lojabrinquedos.fantasystar.model.repository;

import java.util.List;

import org.springframework.data.mongodb.repository.MongoRepository;
import com.lojabrinquedos.fantasystar.model.entity.Brinquedo;

public interface BrinquedoRepository extends MongoRepository<Brinquedo, String> {

    Brinquedo deleteByNome(String nome);

    List<Brinquedo> findByNomeContains(String nome);



}
