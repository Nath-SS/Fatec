<?php
class Conexao
{
    static function conectar()
    {
        //iniciando a conexão com mysql e o bd
        $con = new PDO("mysql:host=localhost;port=3307;dbname=meubancodedados","root","usbw"); 
        //ativando exibição de erros do PDO
        $con->setAttribute(PDO::ATTR_ERRMODE,PDO::ERRMODE_EXCEPTION);
        return $con; //retornando a conexão com o BD
    }
}
?>