package com.lojabrinquedos.fantasystar.model.entity;

import org.springframework.data.mongodb.core.mapping.Document;
import jakarta.persistence.Id;

@Document("categoria")
public class Categoria {

    @Id
    private String id;
    
    private String nome;
    private String descricao;

    public Categoria(){
    }

    public Categoria(String id, String nome, String descricao) {
        this.id = id;
        this.nome = nome;
        this.descricao = descricao;
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
    public String getDescricao() {
        return descricao;
    }
    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }
}
