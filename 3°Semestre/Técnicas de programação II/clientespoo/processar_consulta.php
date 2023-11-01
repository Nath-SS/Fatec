<!DOCTYPE html>
<html>
<head>
    <title>Consulta de Cliente</title>
</head>
<body>

<h2>Consulta de Cliente</h2>

<?php
require_once 'Clientes.php'; // Inclua o arquivo com a classe Clientes
$cliente = new Clientes();
$cliente->nome = $_POST['nome']; //insiro no atributo nome o resultado recebido do POST
$resultado = $cliente->consultarCliente(); //chamo o método consultarCliente, que vai buscar se existe cliente com o nome recebido do formulario
if ($resultado) {  //testo se houve resultado na consulta
    echo "<table border='1'>";
    echo "<tr><th>Código Cliente</th><th>Nome</th><th>Email</th><th>Data de Nascimento</th></tr>";
    //foreach ($resultado as $registro) { //como é no máximo 1 registro, não uso foreach
            echo "<tr>";
            //exibo as colunas da tabela que retornaram no objeto $resultado:
            echo "<td>{$resultado->codcliente}</td>"; 
            echo "<td>{$resultado->Nome}</td>";
            echo "<td>{$resultado->Email}</td>";
            echo "<td>{$resultado->DataNascimento}</td>";
            echo "<td>{$resultado->RG}</td>";
            echo "<td>{$resultado->CPF}</td>";
            echo "<td>{$resultado->Endereco}</td>";
            echo "</tr>";
    //}
    echo "</table>";
} else {
    echo "Cliente não encontrado";
}
?>

</body>
</html>