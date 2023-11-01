<?php
class Clientes
{
    //atributos (mesmos atributos da tabela do BD)
    private $codcliente;
    private $nome;
    private $email;
    private $dataNascimento;
    private $rg;
    private $cpf;
    private $endereco;


    //get e set 
	// PESQUISA: O QUE SÃO OS UNDERLINES DUPLOS : __ ANTES DOS MÉTODOS GET E SET?

    function __get($atributo) { return $this->$atributo; }
    function __set($atributo, $valor) { $this->$atributo = $valor; }

    function __construct() //será executado automaticamente ao usar esta classe
    {
        include_once "Conexao.php"; //incluindo classe de conexão
    }


    //método cadastrar
    function inserirCliente()
    {
        $con = Conexao::conectar(); //carregar a conexão
        $cmd = $con->prepare("INSERT INTO clientes (nome,email,dataNascimento,rg,cpf,endereco) VALUES (:nome,:email,:dataNascimento,:rg,:cpf,:endereco)");
        //enviando valores para os parâmetros
        $cmd->bindParam(":nome",    $this->nome);
        $cmd->bindParam(":email",   $this->email);
        $cmd->bindParam(":dataNascimento", $this->dataNascimento);
        $cmd->bindParam(":rg", $this->rg);
        $cmd->bindParam(":cpf", $this->cpf);
        $cmd->bindParam(":endereco", $this->endereco);

        $cmd->execute();//executando o comando

        if ($cmd->rowCount() > 0) 
            {
                return true; // Inserção bem-sucedida
            } 
        else 
            {
                return false; // Inserção falhou
            }
    }

    //método consultar
    function listarClientes()
    {
        $con = Conexao::conectar();//iniciar conexão com BD
        $cmd = $con->prepare("SELECT * FROM clientes");
        $cmd->execute();
        return $cmd->fetchAll(PDO::FETCH_OBJ); //retorna os dados em forma de matriz
    }

    //método excluir
    function removerCliente()
    {
        try{
            $con = Conexao::conectar(); //carregar a conexão
            $cmd = $con->prepare("DELETE FROM clientes WHERE nome = :nome "); //enviando valor para o parâmetro
            $cmd->bindParam(":nome", $this->nome); //valor do parâmetro
            $cmd->execute(); //executando o comando
            return true;
        }
        catch (PDOException $e){
            
            die("Erro ao excluir cliente: ". $e->getMessage());

        }
    }

    //método atualizar
    function atualizar()
    {
        $con = Conexao::conectar(); //carregar a conexão
        $cmd = $con->prepare("UPDATE clientes SET
            nome    = :nome, 
            email   = :email, 
            dataNascimento = :dataNascimento
            rg = :rg
            cpf = :cpf
            endereco = :endereco
        WHERE nome = :nome");
        //enviando valores para os parâmetros
        $cmd->bindParam(":nome",    $this->nome);
        $cmd->bindParam(":email",   $this->email);
        $cmd->bindParam(":dataNascimento", $this->dataNascimento);
        $cmd->bindParam(":rg", $this->rg);
        $cmd->bindParam(":cpf", $this->cpf);
        $cmd->bindParam(":endereco", $this->endereco);
        $cmd->execute();//executando o comando
    }

    //método retornar
    function consultarCliente()
    {
        try{
            $con = Conexao::conectar();//iniciar conexão com BD
            $cmd = $con->prepare("SELECT * FROM clientes WHERE nome = :nome");
            $cmd->bindParam(":nome", $this->nome);
            $cmd->execute();
            return $cmd->fetch(PDO::FETCH_OBJ); //retorna os dados em forma de vetor
        }
        catch (PDOException $e){
            die("Cliente não encontrado:". $e->getMessage());
        }
    }

}
?>