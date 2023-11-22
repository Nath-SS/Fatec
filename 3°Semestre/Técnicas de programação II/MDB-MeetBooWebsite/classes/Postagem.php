<?php


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

        /*$post = new Post();
        $teste = $post->getDescPost();
        echo($teste);*/
        $conexao = Conexao::pegarConexao();


        //Pegar nome

        $stmtU = $conexao->query("SELECT idUsuario FROM tbUsuario WHERE nomeUsuario = '" . $_SESSION['User'] . "'");
        $resultado = $stmtU->fetch();
        $postagem->setIdUsuario($resultado['idUsuario']);

        
        // echo "<pre>";
        // var_dump($postagem);
        // echo "</pre>";
        
        
        //Postagem

        $stmt = $conexao->prepare(" INSERT INTO tbPost (idUsuario, descPost, tituloPost, generoPost, caminhoImagem, nomeImagem)
                                    VALUES (?, ?, ?, ?, ?, ?) ");

        $stmt->bindValue(1, $postagem->getIdUsuario());
        $stmt->bindValue(2, $postagem->getDescPost());
        $stmt->bindValue(3, $postagem->getTituloPost());
        $stmt->bindValue(4, $postagem->getGeneroPost());
        $stmt->bindValue(5, $postagem->getCaminhoImagem());
        $stmt->bindValue(6, $postagem->getNomeImagem());
        $stmt->execute();

        header("Location: home.php");
       

    }

    public function listar(){
        $conexao = Conexao::pegarConexao();
        $querySelect = "SELECT nomeUsuario, descPost, tituloPost, generoPost, caminhoImagem FROM tbPost
                         INNER JOIN tbUsuario ON tbPost.idUsuario = tbUsuario.idUsuario";
        $resultado = $conexao->query($querySelect);
        $listaPost = $resultado->fetchAll();
        return $listaPost;
    }




}




?>