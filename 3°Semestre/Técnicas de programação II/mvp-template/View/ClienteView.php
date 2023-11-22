<?php

class ClienteView {
    public function Adicionado() {
        // Exiba um formulário HTML para inserir informações do cliente.
        echo '<!DOCTYPE html>
        <html>
        
        <head>
            <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <link rel="stylesheet" href="../css/style.css">
            <title>MVP-Template</title>
        </head>
        
        <body>
            <div class="header">
                <div class="header">
                    <ul class="menu">
                        <li class="menu-title"><a href="../index.html">Home</a></li>
                        <li class="menu-items"><a href="#">Clientes</a>
                            <ul class="submenu">
                                <li><a href="../cadastrarCliente.html">Cadastrar Cliente</a></li>
                                <li><a href="../atualizarCliente.html">Atualizar Cliente</a></li>
                                <li><a href="../removerCliente.html">Remover Cliente</a></li>
                                <li><a href="../consultaCliente.html">Consultar Cliente</a></li>
                                <li><a href="../Presenter/ClientePresenter.php">Listar Clientes</a></li>
                            </ul>
                        </li>
                        <li class="menu-items"><a href="#">Pedidos</a>
                            <ul class="submenu">
                                <li><a href="realizarPedido.html">Realizar Pedido</a></li>
                                <li><a href="atualizarPedido.html">Atualizar Pedido</a></li>
                                <li><a href="excluirPedido.html">Excluir Pedido</a></li>
                                <li><a href="consultaPedido.html">Consultar Pedido</a></li>
                                <li><a href="index.php?Classe=Pedido&metodo=listar">Listar Pedidos</a></li>
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
            </div>
        </body>
        </html>';
    }

    public function Listar($clientes){
        $listaClientes = $clientes->listarClientes();
        echo '<!DOCTYPE html>
        <html>
        
        <head>
            <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <link rel="stylesheet" href="../css/style.css">
            <title>MVP-Template</title>
        </head>
        
        <body>
            <div class="header">
                <div class="header">
                    <ul class="menu">
                        <li class="menu-title"><a href="../index.html">Home</a></li>
                        <li class="menu-items"><a href="#">Clientes</a>
                            <ul class="submenu">
                                <li><a href="../cadastrarCliente.html">Cadastrar Cliente</a></li>
                                <li><a href="../atualizarCliente.html">Atualizar Cliente</a></li>
                                <li><a href="../removerCliente.html">Remover Cliente</a></li>
                                <li><a href="../consultaCliente.html">Consultar Cliente</a></li>
                                <li><a href="../Presenter/ClientePresenter.php">Listar Clientes</a></li>
                            </ul>
                        </li>
                        <li class="menu-items"><a href="#">Pedidos</a>
                            <ul class="submenu">
                                <li><a href="realizarPedido.html">Realizar Pedido</a></li>
                                <li><a href="atualizarPedido.html">Atualizar Pedido</a></li>
                                <li><a href="excluirPedido.html">Excluir Pedido</a></li>
                                <li><a href="consultaPedido.html">Consultar Pedido</a></li>
                                <li><a href="index.php?Classe=Pedido&metodo=listar">Listar Pedidos</a></li>
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
            </div>';

            foreach ($listaClientes as $linha){
                echo '<h1>' . $linha['nome'] . '</h1>';
                echo '<h1>' . $linha['email'] . '</h2>';
            }
        echo'
        </body>
        </html>';
    }

    // Outros métodos de visualização, como exibir mensagens de sucesso, etc.
}

?>