<?php
if(isset($_REQUEST["classe"]) && isset($_REQUEST["metodo"])){
    $classe = $_REQUEST["classe"];
    $metodo = $_REQUEST["metodo"];
    include_once "Controller/".$classe."Controller.php";
    $classe .= "Controller";
    $obj = new $classe();
    $obj->$metodo();
    
}else{
    header("location: index.php?classe=Home&metodo=abrir_menu");
}
