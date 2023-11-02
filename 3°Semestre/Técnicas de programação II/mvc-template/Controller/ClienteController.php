<?php
require_once './Model/Cliente.php';

Class ClienteController{
    //utilização dos metodos/funcões da Model, tal como um controle no diagrama de caso de uso
    
    public function listar(){
        $cliente = new Cliente();
        $clientes = $cliente->listarClientes();

        session_start();
        $_SESSION['Clientes'] = $clientes;

        header("location: View/listaClientes.php");
    }

    public function inserir(){
        $cliente = new Cliente();
        $cliente->nome = $_POST['txtNome'];
        $cliente->email = $_POST['txtEmail'];
        $cliente->dataNascimento = $_POST['txtDN'];
        $cliente->rg = $_POST['txtRg'];
        $cliente->cpf = $_POST['txtCpf'];
        $cliente->endereco = $_POST['txtEndereco'];
        $inserido = $cliente->inserirCliente();
        session_start();

        if ($inserido) {
            $_SESSION['classe'] = "Cliente";
            $_SESSION['dados'] = $cliente;
            header("location: View/inserido.php");
   	    } 
        else {
            $_SESSION['falha'] = "<script>alert('Erro ao inserir o cliente.');</script>";;
            header("location: View/cadastrarCliente.php");
        }
    }

    public function remover(){
        $cliente = new Cliente();
        $cliente->nome = $_POST['txtNome'];
        $removido = $cliente->removerCliente();
        session_start();
        if ($removido) {
            $_SESSION['sucesso'] = "<script>alert('Cliente removido com sucesso!');</script>";;
            header("location: View/removerCliente.php");
        } else { 
            $_SESSION['falha'] = "<script>alert('Erro ao remover o cliente.');</script>";;
            header("location: View/removerCliente.php");
        }
    }

    public function consultar(){
        $cliente = new Cliente();
        $cliente->nome = $_POST['txtNome'];
        $consulta = $cliente->consultarCliente();
        session_start();

        if ($consulta) {
            $_SESSION['Clientes'] = $consulta;
            header("location: View/listaClientes.php");  //testo se houve resultado na consulta
        } else {
            $_SESSION['falha'] = "<script>alert('Cliente não encontrado.');</script>";;
            header("location: View/consultarCliente.php");
        }
    }

    public function atualizar(){
        $cliente = new Cliente();
        $cliente->nome = $_POST['txtNome'];
        $cliente->email = $_POST['txtEmail'];
        $cliente->dataNascimento = $_POST['txtDN'];
        $cliente->rg = $_POST['txtRg'];
        $cliente->cpf = $_POST['txtCpf'];
        $cliente->endereco = $_POST['txtEndereco'];
        $atualizado = $cliente->atualizarCliente();
        session_start();
        
        if ($atualizado) {
            $_SESSION['sucesso'] = "<script>alert('Cliente atualizado com sucesso!');</script>";;
            header("location: View/atualizado.php");
   	    } 
        else {
            $_SESSION['falha'] = "<script>alert('Erro ao atualizar o cliente, cliente não encontrado');</script>";;
            header("location: atualizarCliente.html");
	    }
    }
}


?>