<?php

namespace Operator;
class Multiply implements BinaryOperator{
    private static $instance = null;
    private static $symbol = '*';
    private function __construct()
    {
    }
    
    public static function getInstance(){
        if(self::$instance == null){
            self::$instance = new Multiply();
        }
        return self::$instance;
    }
    
    public function calc(float $firstArgument, float $secondArgument)
    {
        return $firstArgument * $secondArgument;
    }
    
    public function getSymbol()
    {
        return self::$symbol;
    }
    
}