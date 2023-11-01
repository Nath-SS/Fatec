<?php
include_once 'clientes.php';
$meuCliente = new Clientes;
    // Receber os dados do formulário
    $meuCliente->nome = $_POST['nome'];
    $meuCliente->email = $_POST['email'];
    $meuCliente->dataNascimento = $_POST['dataNascimento'];
    //$meuCliente->rg = $_POST['rg'];
        //$meuCliente->cpf = $_POST['cpf'];
            //$meuCliente->endereco = $_POST['endereco'];
    

    $inseriu = $meuCliente->inserirCliente();

    if ($inseriu == true)
    {
        echo "Cliente inserido com sucesso!";
    }
    else 
    {
        echo "Erro ao inserir cliente";
    }

?>
