<?php

    require_once('global.php');

    $loginEmail = $_POST['txtEmail'];
    $loginSenha = $_POST['txtSenha'];


    if(isset($loginEmail) && !empty($loginEmail) || isset($loginSenha) && !empty($loginSenha)){

        $usuario = new Usuario();

        $login = $_POST['txtEmail'];
        $senha = $_POST['txtSenha'];

        if($usuario->logar($login, $senha) == true){
            header("Location: home.php");
        }else{
            header("Location: index.php");
        }

    }else{
        header("Location: index.php");
    }


?>
