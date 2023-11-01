<?php
require_once './Model/Pedido.php';

Class PedidoController{    
    //utilização dos metodos/funcões da Model, tal como um controle no diagrama de caso de uso

    public function listar(){
        $pedido = new Pedido();
        $pedidos = $pedido->listarPedidos();

        $_REQUEST['Pedidos'] = $pedidos;

        require_once 'View/listaPedidos.php';
    }

    public function inserir(){
        $pedido = new Pedido();
        $cliente = $_POST['txtNomeCliente'];
        $pedido->valorPedido = $_POST['txtValor'];
        $pedido->dataPedido = $_POST['txtData'];
        $criado = $pedido->criarPedido($cliente);

        if ($criado) {
            $_SESSION['sucesso'] = "<script>alert('Pedido criado com sucesso!');</script>";;
            header("location: menu.php");
   	    } 
        else {
            $_SESSION['falha'] = "<script>alert('Erro ao criar o pedido.');</script>";;
            header("location: menu.php");
        }
    }

    public function remover(){
        $pedido = new Pedido();
        $pedido->idPedido = $_POST['txtId'];
        $removido = $pedido->excluirPedido();
        if ($removido) {
            echo "Pedido excluido com sucesso!";
        } else { 
            echo "Erro ao excluir pedido.";
        }
    }

    public function consultar(){
        $pedido = new Pedido();
        $idPedido = $_POST['txtId'];
        $consulta = $pedido->consultarPedido($idPedido);

        $_REQUEST['Pedidos'] = $consulta;
        
        require_once 'View/listaPedidos.php';
    }

    public function atualizar(){
        $pedido = new Pedido();
        $pedido->idPedido = $_POST['txtId'];
        $pedido->valorPedido = $_POST['txtValor'];
        $pedido->dataPedido = $_POST['txtData'];
        $atualizado = $pedido->atualizarPedido();

        if ($atualizado) {
            echo "Pedido atualizado com sucesso!";
            header("location: menu.php");
   	    } 
        else {
            echo "Erro ao atualizar o pedido.";
	    }
    }
}


?>