package com.lojabrinquedos.fantasystar.model.entity;

import org.springframework.data.mongodb.core.mapping.Document;
import jakarta.persistence.Id;

@Document("brinquedo")
public class Brinquedo {
	
	@Id
	private String id;

	private String caminhoImagem;
	private String nomeImagem;

	private String nome;
	private String categoria;
	private double preco;
	private int qntd;
	private String descricao;
	private boolean destaque;

	public Brinquedo(String id, String nome, String categoria, double preco, int qntd, String descricao, String caminhoImagem, String nomeImagem, boolean destaque) {
		this.id = id;
		this.nome = nome;
		this.categoria = categoria;
		this.preco = preco;
		this.qntd = qntd;
		this.descricao = descricao;
		this.caminhoImagem = caminhoImagem;
		this.nomeImagem = nomeImagem;
		this.destaque = destaque;
	}
	
	public Brinquedo() {
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
	
	public String getCategoria() {
		return categoria;
	}

	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}

	public double getPreco() {
		return preco;
	}

	public void setPreco(double preco) {
		this.preco = preco;
	}

	public int getQntd() {
		return qntd;
	}

	public void setQntd(int qntd) {
		this.qntd = qntd;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public String getCaminhoImagem() {
		return caminhoImagem;
	}

	public void setCaminhoImagem(String caminhoImagem) {
		this.caminhoImagem = caminhoImagem;
	}

	public String getNomeImagem() {
		return nomeImagem;
	}

	public void setNomeImagem(String nomeImagem) {
		this.nomeImagem = nomeImagem;
	}
	
	public boolean isDestaque() {
		return destaque;
	}

	public void setDestaque(boolean destaque) {
		this.destaque = destaque;
	}
	
	
	

}
