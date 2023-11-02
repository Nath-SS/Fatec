<?php
    try{
        session_start();
        $lista = $_SESSION['Clientes'];
    }
    catch(Exception $e){
        echo '<pre>';
            print_r($e);
        echo '</pre>';

        echo $e->getMessage(); 
    }

    #var_dump($lista);
    foreach($lista as $linha){
        echo $linha['nome'];
        
    }
?>