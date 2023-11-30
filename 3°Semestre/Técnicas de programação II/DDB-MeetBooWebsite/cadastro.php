<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./css/styleCadastro.css">
    <link rel="shortcut icon" type="image/x-icon" href="./img/meetboonenem.ico">


    <script src="./js/valida-senha.js"></script>

    <title>Cadastro</title>
</head>

<body>

    <?php
        session_start();

        if(isset($_SESSION['TryAgain'])){
            echo($_SESSION['TryAgain']);
            session_destroy();

        }elseif(isset($_SESSION['Senha'])){
            echo($_SESSION['Senha']);
            session_destroy();
        }
    ?>
    <section class="principal">
        <div class="container">
            <img src="./img/logoMeetboo.png" alt="Logotipo da empresa com livros roxos desenhados ao canto">
            <form method="post" action="cadastrar-usuario.php">
                <input type="text" name="txtName" placeholder="Nome de usuario">
                <input type="email" name="txtEmail" placeholder="Email">
                <input type="password" id="password" name="txtSenha" onkeyup='check();' placeholder="Senha">
                <input type="password" id="confirm_password" name="txtConfirmSenha" onkeyup='check();' placeholder="Confirmar senha">
                <span id='message'></span>
                <button class="btn-cadastro">Cadastre-se</button>
            </form>
            <p class="paragra">Ao se cadastrar, você concordara com</p>
            <p>nossos <a href="">Termos</a> e <a href="">Condições</a></p>
        </div>
        <footer>
            <ul class="generos">
                <li><a href="">Suspense</a></li>
                <li><a href="">Ficção Científica</a></li>
                <li><a href="">Fantasia</a></li>
                <li><a href="">Terror</a></li>
                <li><a href="">Cristão</a></li>
                <li><a href="">Romance</a></li>
            </ul>
            <p>© MeetBoo todos os direitos reservados<br>
                Brasil, 2021
            </p>
        </footer>
    </section>
</body>

</html>