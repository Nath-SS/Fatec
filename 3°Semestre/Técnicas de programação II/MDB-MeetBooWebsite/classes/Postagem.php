<?php

use MongoDB\BSON\ObjectID;
class Postagem{

    private $idUsuario;
    private $descPost;
    private $tituloPost;
    private $generoPost;
    private $caminhoImagem;
    private $nomeImagem;

    public function getIdUsuario(){
        return $this->idUsuario;
    }

    public function getDescPost(){
        return $this->descPost;
    }

    public function getTituloPost(){
        return $this->tituloPost;
    }

    public function getGeneroPost(){
        return $this->generoPost;
    }

    public function getCaminhoImagem(){
        return $this->caminhoImagem;
    }

    public function getNomeImagem(){
        return $this->nomeImagem;
    }


    public function setIdUsuario($id){
        $this->idUsuario = $id;
    }

    public function setDescPost($desc){
        $this->descPost = $desc;
    }

    public function setTituloPost($titulo){
        $this->tituloPost = $titulo;
    }

    public function setGeneroPost($genero){
        $this->generoPost = $genero;
    }

    public function setCaminhoImagem($caminho){
        $this->caminhoImagem = $caminho;
    }
    
    public function setNomeImagem($nome){
        $this->nomeImagem = $nome;
    }

    public function postar($postagem){

        $conexao = ConexaoMDB::pegarConexao();
        $banco = $conexao->selectDatabase('MeetBooMDB');
        $colecaoUsuario = $banco->selectCollection('tbUsuario');
        $colecaoPost = $banco->selectCollection('tbPost');

        //Pegar nome

        $usuario = $colecaoUsuario->findOne(['nomeUsuario' => $_SESSION['User']]);
        $postagem->setIdUsuario($usuario['_id']);

        
        
        //Postagem
        $documentoPostagem = [
            'idUsuario' => $postagem->getIdUsuario(),
            'descPost' => $postagem->getDescPost(),
            'tituloPost' => $postagem->getTituloPost(),
            'generoPost' => $postagem->getGeneroPost(),
            'caminhoImagem' => $postagem->getCaminhoImagem(),
            'nomeImagem' => $postagem->getNomeImagem(),
        ];

        $colecaoPost->insertOne($documentoPostagem);

        header("Location: home.php");

    }

    public function listar(){
        $conexao = ConexaoMDB::pegarConexao();
        $banco = $conexao->selectDatabase('MeetBooMDB');
        $colecaoUsuario = $banco->selectCollection('tbUsuario');
        $colecaoPost = $banco->selectCollection('tbPost');

        $pipeline =[
            [
                '$lookup' => [
                    'from' => 'tbUsuario',
                    'localField' => 'idUsuario',
                    'foreignField' => '_id',
                    'as' => 'usuario',
                ],
            ],

            [
                '$unwind' => '$usuario',
            ],

            [
                '$project' => [
                    'nomeUsuario' => '$usuario.nomeUsuario',
                    'descPost' => '$descPost',
                    'tituloPost' => '$tituloPost',
                    'generoPost' => '$generoPost',
                    'caminhoImagem' => '$caminhoImagem',
                ],
            ],
        ];

        $resultados = $colecaoPost->aggregate($pipeline);
        return iterator_to_array($resultados);
    }




}




?>