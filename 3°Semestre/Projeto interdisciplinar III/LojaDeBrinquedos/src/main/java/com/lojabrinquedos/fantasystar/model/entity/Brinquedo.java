package com.lojabrinquedos.fantasystar.model.entity;

import org.springframework.data.mongodb.core.mapping.Document;

import jakarta.persistence.Id;

@Document("brinquedo")
public class Brinquedo {
	
	@Id
	private String id;
	private String nome;
	
	

}
