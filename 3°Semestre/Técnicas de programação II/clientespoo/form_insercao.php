<!DOCTYPE html>
<html>
<head>
    <title>Formulário de Inserção de Clientes</title>
</head>
<body>

<h2>Formulário de Inserção de Clientes</h2>

<form action="processar_inclusao.php" method="post">
    <label for="nome">Nome:</label><br>
    <input type="text" id="nome" name="nome" required><br><br>
    
    <label for="email">Email:</label><br>
    <input type="email" id="email" name="email" required><br><br>
    
    <label for="dataNascimento">Data de Nascimento:</label><br>
    <input type="date" id="dataNascimento" name="dataNascimento" required><br><br>

    <label for="rg">RG:</label><br>
    <input type="text" id="rg" name="rg" required><br><br>

    <label for="cpf">CPF:</label><br>
    <input type="text" id="cpf" name="cpf" required><br><br>

    <label for="endereco">Endereço:</label><br>
    <input type="text" id="endereco" name="endereco" required><br><br>
    
    <input type="submit" value="Inserir Cliente">
</form>

</body>
</html>
