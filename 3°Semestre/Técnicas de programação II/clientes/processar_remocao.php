<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $nome = $_POST["nome"];
include_once("dbconfig.php");
    

    try {
        // Conectar ao banco de dados usando PDO
        $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        // Remover o cliente usando prepared statement
        $stmt = $conn->prepare("DELETE FROM Clientes WHERE Nome = :nome");
        $stmt->bindParam(':nome', $nome);
        $stmt->execute();

        echo "Cliente removido com sucesso!";
    } catch (PDOException $e) {
        echo "Erro ao remover cliente: " . $e->getMessage();
    }

    // Fechar a conexão com o banco de dados
    $conn = null;
} else {
    echo "Erro: Acesso inválido à página.";
}
?>
