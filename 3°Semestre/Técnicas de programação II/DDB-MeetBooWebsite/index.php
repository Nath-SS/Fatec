<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./css/styleIndex.css">
    <link rel="shortcut icon" type="image/x-icon" href="./img/meetboonenem.ico">
    <title>Login</title>
</head>

<body>
    <?php
        session_start();

        if(isset($_SESSION['Sucess'])){
            echo($_SESSION['Sucess']);
            session_destroy();

        }
    ?>
    <section class="principal">
        <div class="imgContainer">
            <img src="./img/asdasd.jfif" alt="Homem digitando seu login em um celular">
        </div>
        <div class="container">
            <img src="./img/logoMeetboo.png" alt="Logotipo da empresa com livros roxos desenhados ao canto">
            <form method="post" action="login.php">
                <input type="email" name="txtEmail" placeholder="Email">
                <input type="password" name="txtSenha" placeholder="Senha">
                <a href="">Esqueci minha senha.</a>
                <button class="btn-login">Entrar</button>
            </form>
            <p class="paragra">Não possui uma conta? <a href="cadastro.php">Cadastre-se</a></p>
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