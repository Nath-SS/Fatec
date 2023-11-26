<?php

    require_once 'global.php';

    $senha = $_POST['txtSenha'];
    $confirmaSenha = $_POST['txtConfirmSenha'];

    if($senha != $confirmaSenha){
        $_SESSION['Senha'] = "<script type='text/javascript'>alert('Confirme sua senha');</script>";
        header("Location: cadastro.php");
    }else{
        $hashSenha = password_hash($senha, PASSWORD_DEFAULT);
        try{
            $usuario = new Usuario();
            $usuario->setNomeUsuario($_POST['txtName']);
            $usuario->setEmailUsuario($_POST['txtEmail']);
            $usuario->setSenhaUsuario($hashSenha);
            echo $usuario->cadastrar($usuario);

        }
        catch(Exception $e){
            echo '<pre>';
                print_r($e);
            echo '<pre>';
            echo $e->getMessage();

        }
    }

?>