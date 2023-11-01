<?php
class Pedido{

    private $idPedido;
    private $idCliente;
    private $numPedido;
    private $dataPedido;

    function __get($atributo) { return $this->$atributo; }
    function __set($atributo, $valor) { $this->$atributo = $valor; }

    function __construct() {
        include_once "Conexao.php";
    }

    public function realizarPedido(){
        $conexao = Conexao::pegarConexao();

        $stmtC = $conexao->query("SELECT idCliente FROM tbCliente WHERE nomeCliente = '" .$_SESSION['User'] . "'");
        $resultado = $stmtC->fetch();
        $pedido->setIdCliente($resultado['idCliente']);

        $stmt = $conexao->prepare(" INSERT INTO tbPedido (idCliente, numPedido, dataPedido)
                                                VALUES(?, ?, ?)");

        $stmt->bindValue(1, $pedido->getIdCliente());
        $stmt->bindValue(2, $pedido->getNumPedido());
        $stmt->bindValue(3, $pedido->getDataPedido());
    }

    public function listarPedidos(){
        $conexao = Conexao::pegarConexao();

        $querySelect = "SELECT nomeCliente, numPedido, dataPedido FROM tbPedido
                         INNER JOIN tbCliente ON tbPedido.idCliente = tbCliente.idCliente";

        $resultado = $conexao->query($querySelect);
        $listaPedidos = $resultado->fetchAll();
        return $listaPedidos;
    }
}



?>