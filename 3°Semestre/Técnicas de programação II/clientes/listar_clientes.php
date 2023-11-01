<!DOCTYPE html>
<html>
<head>
    <title>Listar Clientes</title>
</head>
<body>

<h2>Lista de Clientes</h2>

<?php
include_once("dbconfig.php");
try {
    // Conectar ao banco de dados usando PDO
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Consulta todos os clientes usando prepared statement
    $stmt = $conn->prepare("SELECT Nome, Email, DataNascimento FROM Clientes");
    $stmt->execute();

    // Exibir resultados em uma tabela
    echo "<table border='1'>";
    echo "<tr><th>Nome</th><th>Email</th><th>Data de Nascimento</th></tr>";
    while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
        echo "<tr>";
        echo "<td>" . $row['Nome'] . "</td>";
        echo "<td>" . $row['Email'] . "</td>";
        echo "<td>" . $row['DataNascimento'] . "</td>";
        echo "</tr>";
    }
    echo "</table>";
} catch (PDOException $e) {
    echo "Erro: " . $e->getMessage();
}

// Fechar a conexão com o banco de dados
$conn = null;
?>

</body>
</html>