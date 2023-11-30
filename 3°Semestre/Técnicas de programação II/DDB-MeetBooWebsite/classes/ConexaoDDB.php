<?php

session_start();
require_once 'vendor/autoload.php';

use Aws\DynamoDb\DynamoDbClient;
use Aws\DynamoDb\Marshaler;

class ConexaoDDB{

    public function pegarConexao(){
        $client = new DynamoDbClient([
            'region' => 'sa-east-1',
            'version' => 'latest',
            'credentials' => [
                'key' => 'AKIAVQPHQ63LCKBNNOUR',
                'secret' => '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',
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