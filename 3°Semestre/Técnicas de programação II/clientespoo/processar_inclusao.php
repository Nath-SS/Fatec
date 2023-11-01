<?php
include_once 'Clientes.php';
 // Inclua o arquivo com a classe Clientes
    // Receber os dados do formulário
if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    $cliente = new Clientes();
    $cliente->nome = $_POST["nome"];
    $cliente->email = $_POST["email"];
    $cliente->dataNascimento = $_POST["dataNascimento"];
    $cliente->rg = $_POST["rg"];
    $cliente->cpf = $_POST["cpf"];
    $cliente->endereco = $_POST["endereco"];
    $inserido = $cliente->inserirCliente();
    if ($inserido) 
	{
        alert("Cliente inserido com sucesso!");
        header("location: index.php");
   	} 
    else 
	{
        echo "Erro ao inserir cliente.";
	}
}
?>
