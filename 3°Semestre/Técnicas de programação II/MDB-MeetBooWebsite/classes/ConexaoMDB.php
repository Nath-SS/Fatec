<?php

session_start();

class ConexaoMDB{

    public static function pegarConexao(){
        $url = "mongodb://localhost:27017";
        $client = new MongoDB\Client($url);
        return $client;
    }
}
 
?>