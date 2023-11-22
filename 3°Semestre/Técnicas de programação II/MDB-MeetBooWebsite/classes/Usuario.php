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
        $conexao = Conexao::pegarConexao();
        
        //validação

        $nomeUsuario = $usuario->getNomeUsuario();
        $emailUsuario = $usuario->getEmailUsuario();


        $stmtL = $conexao->prepare("SELECT * FROM tbUsuario WHERE nomeUsuario = ?");
        $stmtE = $conexao->prepare("SELECT * FROM tbUsuario WHERE emailUsuario = ? ");
        

        $stmtL->bindParam(1, $nomeUsuario);
        $stmtL->execute();
        $stmtE->bindParam(1, $emailUsuario);
        $stmtE->execute();



        if($stmtL->rowCount() > 0 || $stmtE->rowCount() > 0){            
            $_SESSION['TryAgain'] = "<script type='text/javascript'>alert('Usuario ou Email ja existentes, por favor utilize um diferente.');</script>";
            header("Location: cadastro.php");

        }else{

        
        //cadastro
            $stmt = $conexao->prepare("INSERT INTO tbUsuario (nomeUsuario, emailUsuario, senhaUsuario)
                                      VALUES (?, ?, ?) ");

            $stmt->bindParam(1, $usuario->getNomeUsuario());
            $stmt->bindParam(2, $usuario->getEmailUsuario());
            $stmt->bindParam(3, $usuario->getSenhaUsuario());
            $stmt->execute();

            $_SESSION['Sucess'] = "<script type='text/javascript'>alert('Cadastro realizado com sucesso!');</script>";
            header("Location: index.php");

        }        
    }

    public function logar($login, $senha){
        $conexao = Conexao::pegarConexao();

        $stmt = $conexao->prepare("SELECT * FROM tbUsuario WHERE emailUsuario = ? and senhaUsuario = ?");


        $stmt->bindParam(1, $login);
        $stmt->bindParam(2, $senha);
        $stmt->execute();

        if($stmt->rowCount() > 0){
            $dado = $stmt->fetch();

            $_SESSION['User'] = $dado['nomeUsuario'];

            return true;
        }else{
            return false;
        }
    }
}?>