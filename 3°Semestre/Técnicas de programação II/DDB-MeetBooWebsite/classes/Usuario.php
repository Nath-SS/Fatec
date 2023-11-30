<?php


class Usuario{

    private $idUsuario;
    private $nomeUsuario;
    private $emailUsuario;
    private $senhaUsuario;

    public function getIdUsuario(){
        return $this->idUsuario;
    }

    public function getNomeUsuario(){
        return $this->nomeUsuario;
    }

    public function getEmailUsuario(){
        return $this->emailUsuario;
    }

    public function getSenhaUsuario(){
        return $this->senhaUsuario;
    }


    public function setIdUsuario($id){
        $this->idUsuario = $id;
    }

    public function setNomeUsuario($nome){
        $this->nomeUsuario = $nome;
    }

    public function setEmailUsuario($email){
        $this->emailUsuario = $email;
    }

    public function setSenhaUsuario($senha){
        $this->senhaUsuario = $senha;
    }



    public function cadastrar($usuario){
        $conexao = ConexaoDDB::pegarConexao();
        $marshaler = ConexaoDDB::pegarMarshaler();
        

        //validação

        $nomeUsuario = $usuario->getNomeUsuario();
        $emailUsuario = $usuario->getEmailUsuario();


        $params = [
            'TableName' => 'tbUsuario',
            'ProjectionExpression' => 'nomeUsuario, emailUsuario',
            'FilterExpression' => 'nomeUsuario = :nomeUsuario OR emailUsuario = :emailUsuario',
            'ExpressionAttributeValues' => [
                ':nomeUsuario' => ['S' => $nomeUsuario],
                ':emailUsuario' => ['S' => $emailUsuario],
            ],
        ];

        $result = $conexao->scan($params);



        if (!empty($result['Items'])) {
            $_SESSION['TryAgain'] = "<script type='text/javascript'>alert('Usuário ou email já existentes, por favor, utilize diferentes.');</script>";
            header("Location: cadastro.php");
        } else {
            // Cadastro
            $item = [
                'nomeUsuario' => $nomeUsuario,
                'emailUsuario' => $emailUsuario,
                'senhaUsuario' => $usuario->getSenhaUsuario(),
            ];

            $params = [
                'TableName' => 'tbUsuario',
                'Item' => $marshaler->marshalItem($item),
            ];

            $conexao->putItem($params);

            $_SESSION['Sucess'] = "<script type='text/javascript'>alert('Cadastro realizado com sucesso!');</script>";
            header("Location: index.php");
        }     
    }

    public function logar($login, $senha){
        $conexao = ConexaoDDB::pegarConexao();
        $marshaler = ConexaoDDB::pegarMarshaler();

        $params = [
            'TableName' => 'tbUsuario',
            'ProjectionExpression' => 'nomeUsuario, senhaUsuario',
            'FilterExpression' => 'emailUsuario = :emailUsuario',
            'ExpressionAttributeValues' => [
                ':emailUsuario' => ['S' => $login],
            ],
        ];

        $result = $conexao->scan($params);

        foreach ($result['Items'] as $item) {
            $item = $marshaler->unmarshalItem($item);
            if ($item['senhaUsuario'] == $senha) {
                $_SESSION['User'] = $item['nomeUsuario'];
                return true;
            }
        }

        return false;

    }
}?>