<?php
$servername = "localhost"; // Substitua pelo endereço do servidor do seu banco de dados
$username = "root"; // Substitua pelo seu nome de usuário do banco de dados
$password = "usbw"; // Substitua pela sua senha do banco de dados
$dbname = "meubancodedados"; // Substitua pelo nome do seu banco de dados

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Receber os dados do formulário
    $nome = $_POST['nome'];
    $email = $_POST['email'];
    $dataNascimento = $_POST['dataNascimento'];
    $RG= $_POST['RG'];
    $CPF = $_POST['CPF'];
    $endereco = $_POST['endereco'];

    // Preparar a consulta SQL usando um prepared statement
    $stmt = $conn->prepare("INSERT INTO Clientes (Nome, Email, DataNascimento, RG, CPF, endereco) VALUES (:nome, :email, :dataNascimento, :RG, :CPF, :endereco)");

    // Atribuir valores aos parâmetros do prepared statement
    $stmt->bindParam(':nome', $nome);
    $stmt->bindParam(':email', $email);
    $stmt->bindParam(':dataNascimento', $dataNascimento);
    $stmt->bindParam(':RG', $RG);
    $stmt->bindParam(':CPF', $CPF);
    $stmt->bindParam(':endereco', $endereco);

    // Executar a consulta
    $stmt->execute();

    echo "Cliente inserido com sucesso!";
} catch(PDOException $e) {
    echo "Erro ao inserir cliente: " . $e->getMessage();
}

// Fechar a conexão com o banco de dados
$conn = null;
?>
