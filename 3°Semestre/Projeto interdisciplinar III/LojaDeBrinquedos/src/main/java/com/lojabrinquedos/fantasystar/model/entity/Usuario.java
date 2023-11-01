package com.lojabrinquedos.fantasystar.model.entity;

import org.springframework.data.mongodb.core.mapping.Document;
import jakarta.persistence.Id;

@Document("usuario")
public class Usuario {
	
	@Id 
	private String id;
	
	private String nome;
	private String senha;
	private String email;
	private String endereco;
	
	public Usuario() {
		// TODO Auto-generated method stub

	}

	public Usuario(String id, String nome, String senha, String email, String endereco) {
		super();
		this.id = id;
		this.nome = nome;
		this.senha = senha;
		this.email = email;
		this.endereco = endereco;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		this.senha = senha;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}
	
	

}
