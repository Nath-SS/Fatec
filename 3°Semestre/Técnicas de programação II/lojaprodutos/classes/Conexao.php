<?php
class Conexao{

    public static function pegarConexao(){
        $servidor = "localhost";
        $banco = "lojaProdutos";
        $usuario = "root";
        $senha = "usbw";

        try{
            $conexao = new PDO("mysql:host=$servidor;dbname=$banco",$usuario,$senha);

            $conexao->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $conexao->exec("SET CHARACTER SET utf8");
            return $conexao;
        
        }catch(PDOException $err){
            echo "Error: ".$err -> getMessage();
        }

    }
}
?>