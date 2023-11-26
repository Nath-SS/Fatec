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
        $conexao = ConexaoMDB::pegarConexao();
        $banco = $conexao->selectDatabase('MeetBooMDB');
        $colecao = $banco->selectCollection('tbUsuario');
        
        //validação

        $nomeUsuario = $usuario->getNomeUsuario();
        $emailUsuario = $usuario->getEmailUsuario();
        
        $resultadoNome = $colecao->findOne(['nomeUsuario' => $nomeUsuario]);
        $resultadoEmail = $colecao->findOne(['emailUsuario' => $emailUsuario]);

        if($resultadoNome || $resultadoEmail){
            $_SESSION['TryAgain'] = "<script type='text/javascript'>alert('Usuario ou Email ja existentes, por favor utilize um diferente.');</script>";
            header("Location: cadastro.php");
        }else{
        
        //cadastro
            $usuarioDocument = [
                'nomeUsuario' => $usuario->getNomeUsuario(),
                'emailUsuario' => $usuario->getEmailUsuario(),
                'senhaUsuario' => $usuario->getSenhaUsuario()
            ];

            $colecao->insertOne($usuarioDocument);

            $_SESSION['Sucess'] = "<script type='text/javascript'>alert('Cadastro realizado com sucesso!');</script>";
            header("Location: index.php");

        }        
    }

    public function logar($login, $senha){
        $conexao = ConexaoMDB::pegarConexao();
        $banco = $conexao->selectDatabase('MeetBooMDB');
        $colecao = $banco->selectCollection('tbUsuario');

        $usuario = $colecao->findOne(['emailUsuario' => $login]);

        if (!empty($usuario)) {
            // Verificar a senha usando password_verify
            if (password_verify($senha, $usuario['senhaUsuario'])) {
                // Senha válida, armazene na sessão ou tome outras medidas necessárias
                $_SESSION['User'] = $usuario['nomeUsuario'];
                return true;
            }
        }else{
        // Usuário não encontrado ou senha inválida
            return false;
        }
    }
}?>