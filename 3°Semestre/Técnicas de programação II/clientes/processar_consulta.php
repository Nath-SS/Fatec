<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    include_once "Clientes.php";
    $cliente = new Clientes();
    $cliente->nome = $_POST["nome"];

    try {
        // Conectar ao banco de dados usando PDO
        $row = $cliente->consultarCliente();

        // Consulta usando prepared statement
        $stmt = $conn->prepare("SELECT Nome, Email, DataNascimento, RG, CPF, Endereco FROM Clientes WHERE Nome = :nome");
        $stmt->bindParam(':nome', $nome);
        $stmt->execute();

        // Verificar se há resultados
        if ($stmt->rowCount() > 0) {
            // Exibir informações do cliente
            $row = $stmt->fetch(PDO::FETCH_ASSOC);
            echo "Nome: " . $row['Nome'] . "<br>";
            echo "Email: " . $row['Email'] . "<br>";
            echo "Data de Nascimento: " . $row['DataNascimento'] . "<br>";
            echo "RG: " . $row['RG'] . "<br>";
            echo "CPF: " . $row['CPF'] . "<br>";
            echo "Endereço: " . $row['Endereco'];
        } else {
            echo "Cliente não encontrado.";
        }
    } catch (PDOException $e) {
        echo "Erro: " . $e->getMessage();
    }

    // Fechar a conexão com o banco de dados
    $conn = null;
} else {
    echo "Erro: Acesso inválido à página.";
}
?>