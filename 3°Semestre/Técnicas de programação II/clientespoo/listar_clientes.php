<!DOCTYPE html>
<html>
<head>
    <title>Listar Clientes</title>
</head>
<body>

<h2>Lista de Clientes</h2>

<?php
require_once 'Clientes.php'; // Inclua o arquivo com a classe Clientes
$cliente = new Clientes();
$resultado = $cliente->listarClientes();
if ($resultado) {
    echo "<table border='1'>";
    echo "<tr><th>Código Cliente</th><th>Nome</th><th>Email</th><th>Data de Nascimento</th></tr>";
    foreach ($resultado as $registro) {
            echo "<tr>";
            echo "<td>{$registro->codcliente}</td>";
            echo "<td>{$registro->Nome}</td>";
            echo "<td>{$registro->Email}</td>";
            echo "<td>{$registro->DataNascimento}</td>";
            echo "<td>{$registro->RG}</td>";
            echo "<td>{$registro->CPF}</td>";
            echo "<td>{$registro->Endereco}</td>";
            echo "</tr>";
    }
    echo "</table>";
} else {
    echo "Não há registros na tabela.";
}
?>

</body>
</html>