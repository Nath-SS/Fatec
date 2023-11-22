<?php

//phpinfo();

$url = "mongodb://localhost:27017";
$client = new MongoDB\Client($url);

if($client){
    return 'Funcionou';
}else{
    return 'Deu ruim';
}


 
?>