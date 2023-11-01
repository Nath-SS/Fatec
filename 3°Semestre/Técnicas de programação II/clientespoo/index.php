<!DOCTYPE html>
<html>
<head>
    <title>Menu de Clientes</title>
    <style>
        ul {
            list-style-type: none;
            margin: 0;
            padding: 0;
            overflow: hidden;
            background-color: #333;
        }

        li {
            float: left;
        }

        li a {
            display: block;
            color: white;
            text-align: center;
            padding: 14px 16px;
            text-decoration: none;
        }

        li a:hover {
            background-color: #111;
        }
    </style>
</head>
<body>

<h2>Menu de Clientes</h2>

<ul>
    <li><a href="form_insercao.php">Inserir Cliente</a></li>
    <li><a href="form_consulta.php">Consultar Cliente</a></li>
    <li><a href="listar_clientes.php">Listar Clientes</a></li>
    <li><a href="form_remocao.php">Remover Cliente</a></li>
</ul>

</body>
</html>
