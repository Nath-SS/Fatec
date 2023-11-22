<?php

//phpinfo();

$client = new mongoDB\mongoDBlib\src\Client('mongodb://localhost:27017');

if($client){
    return 'Funcionou';
}else{
    return 'Deu ruim';
}

$database = $cliente->test;
 
?>