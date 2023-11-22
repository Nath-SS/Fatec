<?php

require_once '../Model/Cliente.php';
require_once '../View/ClienteView.php';
$model = new Cliente();
$view = new ClienteView();

class ClientePresenter {
    private $cliente;
    private $clienteView;

    public function __construct($model, $view) {
        $this->cliente = $model;
        $this->clienteView = $view;
    }

    public function processarRequisicao() {
        if (isset($_POST['Adicionar'])) {
            //echo 'deu certo';
            
            $this->cliente->nome = $_POST['txtNome'];
            $this->cliente->email = $_POST['txtEmail'];
            $this->cliente->dataNascimento = $_POST['txtDN'];
            $this->cliente->rg = $_POST['txtRg'];
            $this->cliente->cpf = $_POST['txtCpf'];
            $this->cliente->endereco = $_POST['txtEndereco'];
            $inserido = $this->cliente->inserirCliente();

            if($inserido){
                $this->clienteView->Adicionado();
            }else{
                echo 'falha ao inserir o cliente';
            }

        }else if(isset($_POST['Atualizar'])){
            $this->clienteView->Atualizar();

        }else if(isset($_POST['Consultar'])){
            $this->clienteView->Consultar();

        }else if(isset($_POST['Excluir'])){
            $this->clienteView->Excluir();

        }else{
            $this->clienteView->Listar($this->cliente);
        }
        
    }
}

$clientePresenter = new ClientePresenter($model, $view);
$clientePresenter->processarRequisicao();
?>
