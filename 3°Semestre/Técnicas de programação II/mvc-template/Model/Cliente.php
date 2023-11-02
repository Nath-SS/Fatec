<?php

class Cliente{

    private $idCliente;
    private $nome;
    private $email;
    private $dataNascimento;
    private $rg;
    private $cpf;
    private $endereco;

    function __get($atributo) { return $this->$atributo; }
    function __set($atributo, $valor) { $this->$atributo = $valor; }

    function __construct() {
        include_once "Conexao.php"; 
    }

    function inserirCliente(){ //completo e funcional
        $conexao = Conexao::pegarConexao();
        $cmd = $conexao->prepare("INSERT INTO cliente (nome,email,dataNascimento,rg,cpf,endereco)
                                    VALUES ( ?, ?, ?, ?, ?, ?)");
        $cmd->bindParam(1, $this->nome);
        $cmd->bindParam(2, $this->email);
        $cmd->bindParam(3, $this->dataNascimento);
        $cmd->bindParam(4, $this->rg);
        $cmd->bindParam(5, $this->cpf);
        $cmd->bindParam(6, $this->endereco);

        $cmd->execute();

        if ($cmd->rowCount() > 0) {
            return true; 
        } 
        else {
            return false; 
        }
    }

    function listarClientes(){ //completo e funcional
        $con = Conexao::pegarConexao();
        $querySelect = "SELECT * FROM cliente";
        $cmd = $con->query($querySelect);
        $listaCliente = $cmd->fetchAll();
        return $listaCliente;
    }

    function removerCliente(){ //completo e funcional
        try{
            $con = Conexao::pegarConexao(); 
            $cmd = $con->prepare("DELETE FROM cliente WHERE nome = ? "); 
            $cmd->bindParam(1, $this->nome); 
            $cmd->execute(); 
            return true;
        }
        catch (PDOException $e){
            die("Erro ao excluir cliente: ". $e->getMessage());
        }
    }

    function atualizarCliente(){ //completo e funcional
        $conexao = Conexao::pegarConexao();
        
        $querySelect = $conexao->prepare("SELECT idCliente WHERE nome = ?");
        $querySelect->bindParam(1, $this->nome);
        $this->idCliente = $querySelect->execute();

        $cmd = $conexao->prepare("UPDATE cliente SET
            nome    = ?, 
            email   = ?, 
            dataNascimento = ?,
            rg = ?,
            cpf = ?,
            endereco = ?
        WHERE idCliente = ?");
        
        $cmd->bindParam(1, $this->nome);
        $cmd->bindParam(2, $this->email);
        $cmd->bindParam(3, $this->dataNascimento);
        $cmd->bindParam(4, $this->rg);
        $cmd->bindParam(5, $this->cpf);
        $cmd->bindParam(6, $this->endereco);
        $cmd->bindParam(7, $this->idCliente);
        $cmd->execute();
    }

    function consultarCliente(){ //completo e funcional
        try{
            $conexao = Conexao::pegarConexao();
            $cmd = $conexao->prepare("SELECT * FROM cliente WHERE nome = ?");
            $cmd->bindParam(1, $this->nome);
            $cmd->execute();
            $consultaCliente = $cmd->fetch(PDO::FETCH_OBJ); 
            return $consultaCliente;
        }
        catch (PDOException $e){
            die("Cliente não encontrado:". $e->getMessage());
        }
    }

}
?>