<?php
    try{
        session_start();
        $lista = $_REQUEST['consulta'];
    }
    catch(Exception $e){
        echo '<pre>';
            print_r($e);
        echo '</pre>';

        echo $e->getMessage(); 
    }

    foreach($lista as $linha){
        echo $linha['nome'];
        echo $linha['email'];
        echo $linha['dataNascimento'];
        echo $linha['rg'];
        echo $linha['cpf'];
        echo $linha['endereco'];

    }
?>