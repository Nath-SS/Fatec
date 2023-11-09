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
        if (isset($_POST['Teste'])) {
            $this->clienteView->teste();
            /*$nome = $_POST['nome'];
            $email = $_POST['email'];
            $this->model->adicionarCliente($nome, $email);
            // Você também pode adicionar lógica para exibir uma mensagem de sucesso na View.
            */
        }
        //$this->view->exibirFormularioCliente();
    }
}

$clientePresenter = new ClientePresenter($model, $view);
$clientePresenter->processarRequisicao();
?>
