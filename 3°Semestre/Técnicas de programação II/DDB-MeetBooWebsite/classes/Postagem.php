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
        $conexao = ConexaoDDB::pegarConexao();
        $marshaler = ConexaoDDB::pegarMarshaler();


        //Pegar nome

        $paramsUsuario = [
            'TableName' => 'tbUsuario',
            'ProjectionExpression' => 'idUsuario',
            'FilterExpression' => 'nomeUsuario = :nomeUsuario',
            'ExpressionAttributeValues' => [
                ':nomeUsuario' => ['S' => $_SESSION['User']],
            ],
        ];

        $resultUsuario = $conexao->scan($paramsUsuario);
        $idUsuario = $resultUsuario['Items'][0]['idUsuario']['N'];

        
        
        //Postagem

        $paramsPostagem = [
            'TableName' => 'tbPost',
            'Item' => [
                'idUsuario' => ['N' => $idUsuario],
                'descPost' => ['S' => $postagem->getDescPost()],
                'tituloPost' => ['S' => $postagem->getTituloPost()],
                'generoPost' => ['S' => $postagem->getGeneroPost()],
                'caminhoImagem' => ['S' => $postagem->getCaminhoImagem()],
                'nomeImagem' => ['S' => $postagem->getNomeImagem()],
            ],
        ];

        $conexao->putItem($paramsPostagem);

        header("Location: home.php");
       

    }

    public function listar(){
        $conexao = ConexaoDDB::pegarConexao();
        $marshaler = ConexaoDDB::pegarMarshaler();


        $params = [
            'TableName' => 'tbPost',
            'ProjectionExpression' => 'idUsuario, descPost, tituloPost, generoPost, caminhoImagem, nomeImagem',
        ];

        $result = $conexao->scan($params);

        $listaPost = [];
        foreach ($result['Items'] as $item) {
            $item = $marshaler->unmarshalItem($item);
            $listaPost[] = $item;
        }

        return $listaPost;
    }




}




?>