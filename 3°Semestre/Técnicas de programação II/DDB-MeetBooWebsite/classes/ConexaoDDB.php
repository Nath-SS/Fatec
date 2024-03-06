<?php

session_start();
require_once 'vendor/autoload.php';

use Aws\DynamoDb\DynamoDbClient;
use Aws\DynamoDb\Marshaler;

class ConexaoDDB{

    public function pegarConexao(){
        $client = new DynamoDbClient([
            'region' => '',
            'version' => 'latest',
            'credentials' => [
                'key' => '',
                'secret' => '',
            ],
        ]);
        return $client;
    }

    public function pegarMarshaler(){
        $marshal = new Marshaler();
        return $marshal;
    }

}


?>
