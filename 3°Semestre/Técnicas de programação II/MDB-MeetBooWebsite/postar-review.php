<?php

    require_once 'global.php';

    $review = $_POST['txtReview'];
    $titulo = $_POST['txtTitulo'];
    $genero = $_POST['txtGenero'];
    $imagem = $_FILES['ftFile'];
    $nomeImagem = $imagem['name'];
    $arquivo = $imagem['tmp_name'];


    try{
            
        $Postagem = new Postagem();


        $Postagem->setDescPost($review);
        $Postagem->setTituloPost($titulo);
        $Postagem->setGeneroPost($genero);
            
        //recebendo imagem

        $Postagem->setNomeImagem($nomeImagem);

        $Postagem->setCaminhoImagem('img/');

        move_uploaded_file($arquivo,
                            $Postagem->getCaminhoImagem() . $Postagem->getNomeImagem());

        $Postagem->setCaminhoImagem($Postagem->getCaminhoImagem() . $Postagem->getNomeImagem());


        echo $Postagem->postar($Postagem);

    }
    catch(Exception $e){
        echo '<pre>';
            print_r($e);
        echo '<pre>';
        echo $e->getMessage();

    }
    

?>