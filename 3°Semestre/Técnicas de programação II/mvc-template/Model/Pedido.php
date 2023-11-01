<?php

class Pedido{

    private $idPedido;
    private $idCliente;
    private $valorPedido;
    private $dataPedido;

    function __get($atributo) { return $this->$atributo; }
    function __set($atributo, $valor) { $this->$atributo = $valor; }

    function __construct() {
        include_once "Conexao.php";
    }

    function criarPedido($cliente){ //completo e funcional
        try {
            $conexao = Conexao::pegarConexao();
            $cmdU = $conexao->prepare("SELECT idCliente FROM cliente WHERE nomeCliente = ?");
            $cmdU->bindParam(1, $cliente);
            $cmdU->execute();
            $resultado = $cmdU->fetch();
    
            if ($resultado) {
                $cmd = $conexao->prepare("INSERT INTO pedido (idCliente, valorPedido, dataPedido)
                                         VALUES (?, ?, ?)");
                $cmd->bindParam(1, $resultado['idCliente']);
                $cmd->bindParam(2, $this->valorPedido);
                $cmd->bindParam(3, $this->dataPedido);
                $cmd->execute();
    
                if ($cmd->rowCount() > 0) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false; // Cliente não encontrado
            }
        } catch (PDOException $e) {
            echo "Erro no banco de dados: " . $e->getMessage();
            return false;
        }
    }
    

    function atualizarPedido(){ //incompleto por falta de regra de negócio
        $conexao = Conexao::pegarConexao();
        $cmd = $conexao->prepare("UPDATE pedido SET
            valorPedido = ?,
            dataPedido = ?, 
        WHERE idPedido = ?");

        $cmd->bindParam(1, $this->valorPedido);
        $cmd->bindParam(2, $this->dataPedido);
        $cmd->bindParam(3, $this->idPedido);
        $cmd->execute();

    }

    function excluirPedido(){//completo e funcional
        try{
            $conexao = Conexao::pegarConexao(); 
            $cmd = $conexao->prepare("DELETE FROM pedido WHERE idPedido = ? "); 
            $cmd->bindParam(1, $this->idPedido); 
            $cmd->execute(); 
            return true;
        }
        catch (PDOException $e){
            die("Erro ao excluir equipamento: ". $e->getMessage());
        }
    }

    function listarPedidos(){ //completo e funcional
        $conexao = Conexao::pegarConexao();
        $cmd = $conexao->prepare("SELECT * FROM pedido");
        $cmd->execute();
        return $cmd->fetchAll(PDO::FETCH_OBJ);
    }

    function consultarPedido($idPedido){ //completo e funcional
        try{
            $conexao = Conexao::pegarConexao();
            $cmd = $conexao->prepare("SELECT * FROM pedido WHERE idPedido = ?");
            $cmd->bindParam(1, $idPedido);
            $cmd->execute();
            return $cmd->fetch(PDO::FETCH_OBJ);
        }
        catch (PDOException $e){
            die("Equipamento não encontrado:". $e->getMessage());
        }
        
    }
}
?>