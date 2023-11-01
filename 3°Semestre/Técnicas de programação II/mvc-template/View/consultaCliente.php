<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/style.css">
    <title>Excluir cadastro</title>
</head>
<body>
    <div class="header">
        <ul class="menu">
            <li class="menu-title"><a href="menu.html">Home</a></li>
            <li class="menu-items"><a href="#">Clientes</a>
                <ul class="submenu">
                    <li><a href="cadastrarCliente.php">Cadastrar Cliente</a></li>
                    <li><a href="atualizarCliente.php">Atualizar Cliente</a></li>
                    <li><a href="removerCliente.php">Remover Cliente</a></li>
                    <li><a href="consultaCliente.php">Consultar Cliente</a></li>
                    <li><a href="../index.php?Classe=Cliente&metodo=listar">Listar Clientes</a></li>
                </ul>
            </li>
            <li class="menu-items"><a href="#">Pedidos</a>
                <ul class="submenu">
                    <li><a href="realizarPedido.html">Realizar Pedido</a></li>
                    <li><a href="atualizarPedido.html">Atualizar Pedido</a></li>
                    <li><a href="excluirPedido.html">Excluir Pedido</a></li>
                    <li><a href="consultaPedido.html">Consultar Pedido</a></li>
                    <li><a href="../index.php?Classe=Pedido&metodo=listar">Listar Pedidos</a></li>
                </ul>
            </li>
            <li class="menu-items"><a href="#">Produtos</a>
                <ul class="submenu">
                    <li><a href="adicionarProduto.html">Adicionar Produto</a></li>
                    <li><a href="#">Atualizar Produto</a></li>
                    <li><a href="#">Remover Produto</a></li>
                    <li><a href="#">Consultar Produto</a></li>
                    <li><a href="#">Listar Produtos</a></li>
                </ul>
            </li>
            <li class="menu-items"><a href="#">Entre em contato</a></li>
        </ul>
    </div>
<section class="main">
    <?php
        session_start();
        if(isset($_SESSION['sucesso'])){
            echo($_SESSION['sucesso']);
            session_destroy();
        }else if(isset($_SESSION['falha'])){
            echo($_SESSION['falha']);
            session_destroy();
        }
    
    ?>
    <div class="container-form">
        <h2>Consultar Cliente</h2>

        <form class="form-cadastro" action="../index.php?classe=Cliente&metodo=consultar" method="post">
            <input type="text" name="txtNome" placeholder="Nome" required>
            <button type="submit" class="btn-cadastro">Buscar</button>
        </form>
    </div>
</section>

</body>
</html>
