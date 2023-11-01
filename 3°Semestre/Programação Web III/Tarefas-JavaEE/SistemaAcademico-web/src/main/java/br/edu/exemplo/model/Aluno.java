package br.edu.exemplo.model;
import java.util.Date;

public class Aluno {
	//atributos
	private int ra;
	private String nome;
	private String email;
	private String endereco;
	private Date dataNascimento;
	private String periodo;
	
	//construtor vazio
	public Aluno() {
		// TODO Auto-generated constructor stub
	}
	
	//construtor
	public Aluno(int ra, String nome, String email, String endereco, Date dataNascimento, String periodo) {
		super();
		this.ra = ra;
		this.nome = nome;
		this.email = email;
		this.endereco = endereco;
		this.dataNascimento = dataNascimento;
		this.periodo = periodo;
	}
	
	//getters e setters
	public int getRa() {
		return ra;
	}

	public void setRa(int ra) {
		this.ra = ra;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
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

	public Date getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(Date dataNascimento) {
		this.dataNascimento = dataNascimento;
	}

	public String getPeriodo() {
		return periodo;
	}

	public void setPeriodo(String periodo) {
		this.periodo = periodo;
	}
	
	
	
	
}
